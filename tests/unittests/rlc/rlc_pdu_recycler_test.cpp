/*
 *
 * Copyright 2021-2024 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#include "../support/task_executor_test_doubles.h"
#include "lib/rlc/rlc_pdu_recycler.h"
#include "tests/test_doubles/pdcp/pdcp_pdu_generator.h"
#include "srsran/ran/du_types.h"
#include <gtest/gtest.h>

using namespace srsran;

/// Fixture class for RLC PDU recycler tests
class rlc_pdu_recycler_test : public ::testing::Test
{
protected:
  void SetUp() override
  {
    // init test's logger
    srslog::init();
    logger.set_level(srslog::basic_levels::debug);

    // init RLC logger
    srslog::fetch_basic_logger("RLC", false).set_level(srslog::basic_levels::debug);
    srslog::fetch_basic_logger("RLC", false).set_hex_dump_max_size(-1);

    logger.info("Creating RLC PDU recycler");

    // Create RLC PDU recycler
    pdu_recycler = std::make_unique<rlc_pdu_recycler>(rlc_window_size, rlc_logger);
  }

  void TearDown() override
  {
    // flush logger after each test
    srslog::flush();
  }

  srslog::basic_logger& logger     = srslog::fetch_basic_logger("TEST", false);
  rlc_bearer_logger     rlc_logger = rlc_bearer_logger("RLC", {gnb_du_id_t::min, du_ue_index_t{}, rb_id_t{}, "DL"});
  std::unique_ptr<rlc_pdu_recycler> pdu_recycler;

  manual_task_worker_always_enqueue_tasks other_worker{8};

  const size_t rlc_window_size = 2;
};

TEST_F(rlc_pdu_recycler_test, recycler_memory_reserved)
{
  std::array<std::vector<byte_buffer>, 3>& recycle_bins = pdu_recycler->get_recycle_bins();
  for (const std::vector<byte_buffer>& bin : recycle_bins) {
    EXPECT_EQ(bin.size(), 0);
    EXPECT_EQ(bin.capacity(), rlc_window_size);
  }
}

TEST_F(rlc_pdu_recycler_test, clear_by_executor)
{
  byte_buffer pdu = test_helpers::create_pdcp_pdu(pdcp_sn_size::size12bits, 0xaa, 3, 0xaa);
  EXPECT_TRUE(pdu_recycler->add_discarded_pdu(pdu.deep_copy().value()));
  // Check the PDU is stored in first recycle bin
  std::array<std::vector<byte_buffer>, 3>& recycle_bins = pdu_recycler->get_recycle_bins();
  EXPECT_EQ(recycle_bins[2].size(), 0);
  EXPECT_EQ(recycle_bins[1].size(), 0);
  ASSERT_EQ(recycle_bins[0].size(), 1);
  EXPECT_EQ(recycle_bins[0][0], pdu);

  // Schedule the cleanup in the other_worker task queue. Nothing will be deleted yet.
  pdu_recycler->clear_by_executor(other_worker);
  EXPECT_EQ(recycle_bins[2].size(), 0);
  EXPECT_EQ(recycle_bins[1].size(), 0);
  ASSERT_EQ(recycle_bins[0].size(), 1);
  EXPECT_EQ(recycle_bins[0][0], pdu);

  // Perform the cleanup by the other_worker. Everything will be deleted.
  other_worker.run_pending_tasks();
  for (const std::vector<byte_buffer>& bin : recycle_bins) {
    EXPECT_EQ(bin.size(), 0);
    EXPECT_EQ(bin.capacity(), rlc_window_size);
  }
}

TEST_F(rlc_pdu_recycler_test, clear_multiple_times)
{
  byte_buffer pdu1 = test_helpers::create_pdcp_pdu(pdcp_sn_size::size12bits, 0xaa, 3, 0xaa);
  byte_buffer pdu2 = test_helpers::create_pdcp_pdu(pdcp_sn_size::size12bits, 0xbb, 3, 0xbb);
  byte_buffer pdu3 = test_helpers::create_pdcp_pdu(pdcp_sn_size::size12bits, 0xcc, 3, 0xcc);
  byte_buffer pdu4 = test_helpers::create_pdcp_pdu(pdcp_sn_size::size12bits, 0xdd, 3, 0xdd);
  EXPECT_TRUE(pdu_recycler->add_discarded_pdu(pdu1.deep_copy().value()));
  // Check the PDU is stored in first recycle bin
  std::array<std::vector<byte_buffer>, 3>& recycle_bins = pdu_recycler->get_recycle_bins();
  EXPECT_EQ(recycle_bins[2].size(), 0);
  EXPECT_EQ(recycle_bins[1].size(), 0);
  ASSERT_EQ(recycle_bins[0].size(), 1);
  EXPECT_EQ(recycle_bins[0][0], pdu1);

  // Schedule the cleanup in the other_worker task queue. Nothing will be deleted yet.
  pdu_recycler->clear_by_executor(other_worker);
  EXPECT_EQ(recycle_bins[2].size(), 0);
  EXPECT_EQ(recycle_bins[1].size(), 0);
  ASSERT_EQ(recycle_bins[0].size(), 1);
  EXPECT_EQ(recycle_bins[0][0], pdu1);

  // Discard PDU2, check its stored in second recycle bin
  EXPECT_TRUE(pdu_recycler->add_discarded_pdu(pdu2.deep_copy().value()));
  EXPECT_EQ(recycle_bins[2].size(), 0);
  ASSERT_EQ(recycle_bins[1].size(), 1);
  ASSERT_EQ(recycle_bins[0].size(), 1);
  EXPECT_EQ(recycle_bins[1][0], pdu2);
  EXPECT_EQ(recycle_bins[0][0], pdu1);

  // Perform the cleanup by the other_worker. The first bin will be deleted
  other_worker.run_pending_tasks();
  EXPECT_EQ(recycle_bins[2].size(), 0);
  ASSERT_EQ(recycle_bins[1].size(), 1);
  ASSERT_EQ(recycle_bins[0].size(), 0);

  // Schedule the cleanup in the other_worker task queue. Nothing will be deleted yet.
  pdu_recycler->clear_by_executor(other_worker);
  EXPECT_EQ(recycle_bins[2].size(), 0);
  ASSERT_EQ(recycle_bins[1].size(), 1);
  ASSERT_EQ(recycle_bins[0].size(), 0);

  // Discard PDU3, check its stored in third recycle bin
  EXPECT_TRUE(pdu_recycler->add_discarded_pdu(pdu3.deep_copy().value()));
  ASSERT_EQ(recycle_bins[2].size(), 1);
  ASSERT_EQ(recycle_bins[1].size(), 1);
  EXPECT_EQ(recycle_bins[0].size(), 0);
  EXPECT_EQ(recycle_bins[2][0], pdu3);
  EXPECT_EQ(recycle_bins[1][0], pdu2);

  // Perform the cleanup by the other_worker. The second bin will be deleted
  other_worker.run_pending_tasks();
  EXPECT_EQ(recycle_bins[2].size(), 1);
  ASSERT_EQ(recycle_bins[1].size(), 0);
  ASSERT_EQ(recycle_bins[0].size(), 0);

  // Schedule the cleanup in the other_worker task queue. Nothing will be deleted yet.
  pdu_recycler->clear_by_executor(other_worker);
  EXPECT_EQ(recycle_bins[2].size(), 1);
  ASSERT_EQ(recycle_bins[1].size(), 0);
  ASSERT_EQ(recycle_bins[0].size(), 0);

  // Perform the cleanup by the other_worker. Everything will be deleted.
  other_worker.run_pending_tasks();
  for (const std::vector<byte_buffer>& bin : recycle_bins) {
    EXPECT_EQ(bin.size(), 0);
    EXPECT_EQ(bin.capacity(), rlc_window_size);
  }

  // We start again at first recycling bin
  EXPECT_TRUE(pdu_recycler->add_discarded_pdu(pdu4.deep_copy().value()));
  // Check the PDU is stored in first recycle bin
  EXPECT_EQ(recycle_bins[2].size(), 0);
  EXPECT_EQ(recycle_bins[1].size(), 0);
  ASSERT_EQ(recycle_bins[0].size(), 1);
  EXPECT_EQ(recycle_bins[0][0], pdu4);
}

TEST_F(rlc_pdu_recycler_test, full_recycle_bin)
{
  byte_buffer pdu1 = test_helpers::create_pdcp_pdu(pdcp_sn_size::size12bits, 0xaa, 3, 0xaa);
  byte_buffer pdu2 = test_helpers::create_pdcp_pdu(pdcp_sn_size::size12bits, 0xbb, 3, 0xbb);
  byte_buffer pdu3 = test_helpers::create_pdcp_pdu(pdcp_sn_size::size12bits, 0xcc, 3, 0xcc);

  EXPECT_TRUE(pdu_recycler->add_discarded_pdu(pdu1.deep_copy().value()));
  EXPECT_TRUE(pdu_recycler->add_discarded_pdu(pdu2.deep_copy().value()));

  // Recycle bin is full - any extra PDU will be deleted on the spot and the function returns false
  EXPECT_FALSE(pdu_recycler->add_discarded_pdu(pdu3.deep_copy().value()));

  // Check the PDUs are stored in first recycle bin
  std::array<std::vector<byte_buffer>, 3>& recycle_bins = pdu_recycler->get_recycle_bins();
  EXPECT_EQ(recycle_bins[2].size(), 0);
  EXPECT_EQ(recycle_bins[1].size(), 0);
  ASSERT_EQ(recycle_bins[0].size(), 2);
  EXPECT_EQ(recycle_bins[0][0], pdu1);
  EXPECT_EQ(recycle_bins[0][1], pdu2);

  // Schedule the cleanup in the other_worker task queue. Nothing will be deleted yet.
  pdu_recycler->clear_by_executor(other_worker);
  EXPECT_EQ(recycle_bins[2].size(), 0);
  EXPECT_EQ(recycle_bins[1].size(), 0);
  ASSERT_EQ(recycle_bins[0].size(), 2);
  EXPECT_EQ(recycle_bins[0][0], pdu1);
  EXPECT_EQ(recycle_bins[0][1], pdu2);

  // Perform the cleanup by the other_worker. Everything will be deleted.
  other_worker.run_pending_tasks();
  for (const std::vector<byte_buffer>& bin : recycle_bins) {
    EXPECT_EQ(bin.size(), 0);
    EXPECT_EQ(bin.capacity(), rlc_window_size);
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
