/*
 *
 * Copyright 2021-2024 Software Radio Systems Limited
 *
 * This file is part of srsRAN.
 *
 * srsRAN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsRAN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#pragma once

// This file was generated using the following MATLAB class on 17-05-2024 (seed 0):
//   + "srsPUSCHProcessorUnittest.m"

#include "../../../support/resource_grid_test_doubles.h"
#include "srsran/phy/upper/channel_estimation.h"
#include "srsran/phy/upper/channel_processors/pusch/pusch_processor.h"
#include "srsran/support/file_vector.h"

namespace srsran {

struct test_case_context {
  unsigned               rg_nof_rb;
  unsigned               rg_nof_symb;
  pusch_processor::pdu_t config;
};

struct test_case_t {
  test_case_context                                       context;
  file_vector<resource_grid_reader_spy::expected_entry_t> grid;
  file_vector<uint8_t>                                    sch_data;
  file_vector<uint8_t>                                    harq_ack;
  file_vector<uint8_t>                                    csi_part1;
  file_vector<uint8_t>                                    csi_part2;
};

using csi_part2_size = uci_part2_size_description;

static const std::vector<test_case_t> pusch_processor_test_data = {
    // clang-format off
  {{252, 14, {std::nullopt, {0, 6}, 62751, 4, 248, cyclic_prefix::NORMAL, {modulation_scheme::QPSK, 273.5}, {{0, ldpc_base_graph_type::BG2, true}}, {0, 0, csi_part2_size(0), 1, 20, 6.25, 6.25}, 988, 1, {0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 63608, 1, 2, rb_allocation::make_type1(3, 1), 0, 14, units::bytes(159749), 290}}, {"test_data/pusch_processor_test_input_grid0.dat"}, {"test_data/pusch_processor_test_tb0.dat"}, {"test_data/pusch_processor_test_harq0.dat"}, {"test_data/pusch_processor_test_csi10.dat"}, {"test_data/pusch_processor_test_csi20.dat"}},
  {{89, 14, {std::nullopt, {0, 4}, 59265, 11, 78, cyclic_prefix::NORMAL, {modulation_scheme::QAM64, 622.2}, {{0, ldpc_base_graph_type::BG1, true}}, {0, 0, csi_part2_size(0), 1, 20, 6.25, 6.25}, 477, 1, {0, 1}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 17721, 0, 2, rb_allocation::make_type1(1, 7), 0, 14, units::bytes(159749), 128}}, {"test_data/pusch_processor_test_input_grid1.dat"}, {"test_data/pusch_processor_test_tb1.dat"}, {"test_data/pusch_processor_test_harq1.dat"}, {"test_data/pusch_processor_test_csi11.dat"}, {"test_data/pusch_processor_test_csi21.dat"}},
  {{252, 14, {std::nullopt, {0, 9}, 18537, 91, 161, cyclic_prefix::NORMAL, {modulation_scheme::QAM64, 489.5}, {{0, ldpc_base_graph_type::BG1, true}}, {0, 0, csi_part2_size(0), 1, 20, 6.25, 6.25}, 768, 1, {0, 1, 2, 3}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 9013, 1, 2, rb_allocation::make_type1(58, 15), 0, 14, units::bytes(159749), 986}}, {"test_data/pusch_processor_test_input_grid2.dat"}, {"test_data/pusch_processor_test_tb2.dat"}, {"test_data/pusch_processor_test_harq2.dat"}, {"test_data/pusch_processor_test_csi12.dat"}, {"test_data/pusch_processor_test_csi22.dat"}},
  {{135, 14, {std::nullopt, {0, 5}, 1930, 37, 98, cyclic_prefix::NORMAL, {modulation_scheme::QAM256, 617.3}, {{0, ldpc_base_graph_type::BG1, true}}, {0, 4, csi_part2_size(0), 1, 20, 6.25, 6.25}, 766, 1, {0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 57047, 0, 2, rb_allocation::make_type1(22, 12), 0, 14, units::bytes(159749), 430}}, {"test_data/pusch_processor_test_input_grid3.dat"}, {"test_data/pusch_processor_test_tb3.dat"}, {"test_data/pusch_processor_test_harq3.dat"}, {"test_data/pusch_processor_test_csi13.dat"}, {"test_data/pusch_processor_test_csi23.dat"}},
  {{265, 14, {std::nullopt, {0, 6}, 51985, 20, 245, cyclic_prefix::NORMAL, {modulation_scheme::QAM64, 224}, {{0, ldpc_base_graph_type::BG2, true}}, {0, 4, csi_part2_size(0), 1, 20, 6.25, 6.25}, 66, 1, {0, 1}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 64072, 1, 2, rb_allocation::make_type1(13, 7), 0, 14, units::bytes(159749), 454}}, {"test_data/pusch_processor_test_input_grid4.dat"}, {"test_data/pusch_processor_test_tb4.dat"}, {"test_data/pusch_processor_test_harq4.dat"}, {"test_data/pusch_processor_test_csi14.dat"}, {"test_data/pusch_processor_test_csi24.dat"}},
  {{203, 14, {std::nullopt, {0, 0}, 1510, 188, 15, cyclic_prefix::NORMAL, {modulation_scheme::QAM64, 429.6}, {{0, ldpc_base_graph_type::BG1, true}}, {0, 4, csi_part2_size(0), 1, 20, 6.25, 6.25}, 781, 1, {0, 1, 2, 3}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 32346, 0, 2, rb_allocation::make_type1(30, 19), 0, 14, units::bytes(159749), 504}}, {"test_data/pusch_processor_test_input_grid5.dat"}, {"test_data/pusch_processor_test_tb5.dat"}, {"test_data/pusch_processor_test_harq5.dat"}, {"test_data/pusch_processor_test_csi15.dat"}, {"test_data/pusch_processor_test_csi25.dat"}},
  {{87, 14, {std::nullopt, {0, 5}, 56992, 8, 79, cyclic_prefix::NORMAL, {modulation_scheme::QAM16, 282.9}, {{0, ldpc_base_graph_type::BG2, true}}, {0, 5, csi_part2_size(1), 1, 20, 6.25, 6.25}, 406, 1, {0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 53925, 1, 2, rb_allocation::make_type1(0, 7), 0, 14, units::bytes(159749), 154}}, {"test_data/pusch_processor_test_input_grid6.dat"}, {"test_data/pusch_processor_test_tb6.dat"}, {"test_data/pusch_processor_test_harq6.dat"}, {"test_data/pusch_processor_test_csi16.dat"}, {"test_data/pusch_processor_test_csi26.dat"}},
  {{160, 14, {std::nullopt, {0, 5}, 26138, 137, 23, cyclic_prefix::NORMAL, {modulation_scheme::QPSK, 632.9}, {{0, ldpc_base_graph_type::BG1, true}}, {0, 5, csi_part2_size(1), 1, 20, 6.25, 6.25}, 705, 1, {0, 1}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 63724, 1, 2, rb_allocation::make_type1(48, 25), 0, 14, units::bytes(159749), 614}}, {"test_data/pusch_processor_test_input_grid7.dat"}, {"test_data/pusch_processor_test_tb7.dat"}, {"test_data/pusch_processor_test_harq7.dat"}, {"test_data/pusch_processor_test_csi17.dat"}, {"test_data/pusch_processor_test_csi27.dat"}},
  {{256, 14, {std::nullopt, {0, 6}, 50177, 254, 2, cyclic_prefix::NORMAL, {modulation_scheme::QAM256, 584.7}, {{0, ldpc_base_graph_type::BG1, true}}, {0, 5, csi_part2_size(1), 1, 20, 6.25, 6.25}, 172, 1, {0, 1, 2, 3}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 54691, 1, 2, rb_allocation::make_type1(177, 20), 0, 14, units::bytes(159749), 2326}}, {"test_data/pusch_processor_test_input_grid8.dat"}, {"test_data/pusch_processor_test_tb8.dat"}, {"test_data/pusch_processor_test_harq8.dat"}, {"test_data/pusch_processor_test_csi18.dat"}, {"test_data/pusch_processor_test_csi28.dat"}},
  {{187, 14, {std::nullopt, {0, 3}, 53876, 85, 102, cyclic_prefix::NORMAL, {modulation_scheme::QAM16, 173.9}, {{0, ldpc_base_graph_type::BG2, true}}, {1, 0, csi_part2_size(0), 1, 20, 6.25, 6.25}, 881, 1, {0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 38581, 1, 2, rb_allocation::make_type1(48, 9), 0, 14, units::bytes(159749), 735}}, {"test_data/pusch_processor_test_input_grid9.dat"}, {"test_data/pusch_processor_test_tb9.dat"}, {"test_data/pusch_processor_test_harq9.dat"}, {"test_data/pusch_processor_test_csi19.dat"}, {"test_data/pusch_processor_test_csi29.dat"}},
  {{255, 14, {std::nullopt, {0, 4}, 43187, 180, 75, cyclic_prefix::NORMAL, {modulation_scheme::QAM16, 332.2}, {{0, ldpc_base_graph_type::BG2, true}}, {1, 0, csi_part2_size(0), 1, 20, 6.25, 6.25}, 399, 1, {0, 1}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 33286, 0, 2, rb_allocation::make_type1(53, 14), 0, 14, units::bytes(159749), 831}}, {"test_data/pusch_processor_test_input_grid10.dat"}, {"test_data/pusch_processor_test_tb10.dat"}, {"test_data/pusch_processor_test_harq10.dat"}, {"test_data/pusch_processor_test_csi110.dat"}, {"test_data/pusch_processor_test_csi210.dat"}},
  {{90, 14, {std::nullopt, {0, 2}, 38882, 5, 85, cyclic_prefix::NORMAL, {modulation_scheme::QAM64, 120}, {{0, ldpc_base_graph_type::BG2, true}}, {1, 0, csi_part2_size(0), 1, 20, 6.25, 6.25}, 220, 1, {0, 1, 2, 3}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 6139, 1, 2, rb_allocation::make_type1(1, 3), 0, 14, units::bytes(159749), 100}}, {"test_data/pusch_processor_test_input_grid11.dat"}, {"test_data/pusch_processor_test_tb11.dat"}, {"test_data/pusch_processor_test_harq11.dat"}, {"test_data/pusch_processor_test_csi111.dat"}, {"test_data/pusch_processor_test_csi211.dat"}},
  {{109, 14, {std::nullopt, {0, 1}, 19909, 48, 61, cyclic_prefix::NORMAL, {modulation_scheme::QAM256, 332.2}, {{0, ldpc_base_graph_type::BG2, true}}, {1, 4, csi_part2_size(0), 1, 20, 6.25, 6.25}, 78, 1, {0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 46285, 0, 2, rb_allocation::make_type1(42, 6), 0, 14, units::bytes(159749), 572}}, {"test_data/pusch_processor_test_input_grid12.dat"}, {"test_data/pusch_processor_test_tb12.dat"}, {"test_data/pusch_processor_test_harq12.dat"}, {"test_data/pusch_processor_test_csi112.dat"}, {"test_data/pusch_processor_test_csi212.dat"}},
  {{224, 14, {std::nullopt, {0, 3}, 35168, 10, 214, cyclic_prefix::NORMAL, {modulation_scheme::QAM256, 636}, {{0, ldpc_base_graph_type::BG1, true}}, {1, 4, csi_part2_size(0), 1, 20, 6.25, 6.25}, 152, 1, {0, 1}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 39247, 1, 2, rb_allocation::make_type1(4, 6), 0, 14, units::bytes(159749), 278}}, {"test_data/pusch_processor_test_input_grid13.dat"}, {"test_data/pusch_processor_test_tb13.dat"}, {"test_data/pusch_processor_test_harq13.dat"}, {"test_data/pusch_processor_test_csi113.dat"}, {"test_data/pusch_processor_test_csi213.dat"}},
  {{236, 14, {std::nullopt, {0, 8}, 59485, 6, 230, cyclic_prefix::NORMAL, {modulation_scheme::QPSK, 530.5}, {{0, ldpc_base_graph_type::BG2, true}}, {1, 4, csi_part2_size(0), 1, 20, 6.25, 6.25}, 377, 1, {0, 1, 2, 3}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 3853, 1, 2, rb_allocation::make_type1(0, 6), 0, 14, units::bytes(159749), 293}}, {"test_data/pusch_processor_test_input_grid14.dat"}, {"test_data/pusch_processor_test_tb14.dat"}, {"test_data/pusch_processor_test_harq14.dat"}, {"test_data/pusch_processor_test_csi114.dat"}, {"test_data/pusch_processor_test_csi214.dat"}},
  {{271, 14, {std::nullopt, {0, 0}, 14457, 91, 180, cyclic_prefix::NORMAL, {modulation_scheme::QAM16, 144.2}, {{0, ldpc_base_graph_type::BG2, true}}, {1, 5, csi_part2_size(1), 1, 20, 6.25, 6.25}, 593, 1, {0}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 48920, 1, 2, rb_allocation::make_type1(62, 10), 0, 14, units::bytes(159749), 939}}, {"test_data/pusch_processor_test_input_grid15.dat"}, {"test_data/pusch_processor_test_tb15.dat"}, {"test_data/pusch_processor_test_harq15.dat"}, {"test_data/pusch_processor_test_csi115.dat"}, {"test_data/pusch_processor_test_csi215.dat"}},
  {{251, 14, {std::nullopt, {0, 2}, 15199, 15, 236, cyclic_prefix::NORMAL, {modulation_scheme::QAM16, 685.1}, {{0, ldpc_base_graph_type::BG2, true}}, {1, 5, csi_part2_size(1), 1, 20, 6.25, 6.25}, 230, 1, {0, 1}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 42267, 1, 2, rb_allocation::make_type1(7, 8), 0, 14, units::bytes(159749), 358}}, {"test_data/pusch_processor_test_input_grid16.dat"}, {"test_data/pusch_processor_test_tb16.dat"}, {"test_data/pusch_processor_test_harq16.dat"}, {"test_data/pusch_processor_test_csi116.dat"}, {"test_data/pusch_processor_test_csi216.dat"}},
  {{114, 14, {std::nullopt, {0, 0}, 2620, 33, 81, cyclic_prefix::NORMAL, {modulation_scheme::QPSK, 609}, {{0, ldpc_base_graph_type::BG2, true}}, {1, 5, csi_part2_size(1), 1, 20, 6.25, 6.25}, 643, 1, {0, 1, 2, 3}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 27593, 1, 2, rb_allocation::make_type1(10, 20), 0, 14, units::bytes(159749), 264}}, {"test_data/pusch_processor_test_input_grid17.dat"}, {"test_data/pusch_processor_test_tb17.dat"}, {"test_data/pusch_processor_test_harq17.dat"}, {"test_data/pusch_processor_test_csi117.dat"}, {"test_data/pusch_processor_test_csi217.dat"}},
  {{269, 14, {std::nullopt, {0, 10}, 48952, 77, 192, cyclic_prefix::NORMAL, {modulation_scheme::QAM64, 193.4}, {{0, ldpc_base_graph_type::BG2, true}}, {10, 0, csi_part2_size(0), 1, 20, 6.25, 6.25}, 544, 1, {0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 42474, 1, 2, rb_allocation::make_type1(12, 24), 0, 14, units::bytes(159749), 516}}, {"test_data/pusch_processor_test_input_grid18.dat"}, {"test_data/pusch_processor_test_tb18.dat"}, {"test_data/pusch_processor_test_harq18.dat"}, {"test_data/pusch_processor_test_csi118.dat"}, {"test_data/pusch_processor_test_csi218.dat"}},
  {{214, 14, {std::nullopt, {0, 10}, 12637, 11, 203, cyclic_prefix::NORMAL, {modulation_scheme::QAM256, 394.2}, {{0, ldpc_base_graph_type::BG1, true}}, {10, 0, csi_part2_size(0), 1, 20, 6.25, 6.25}, 307, 1, {0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 59111, 0, 2, rb_allocation::make_type1(0, 11), 0, 14, units::bytes(159749), 260}}, {"test_data/pusch_processor_test_input_grid19.dat"}, {"test_data/pusch_processor_test_tb19.dat"}, {"test_data/pusch_processor_test_harq19.dat"}, {"test_data/pusch_processor_test_csi119.dat"}, {"test_data/pusch_processor_test_csi219.dat"}},
  {{166, 14, {std::nullopt, {0, 1}, 58544, 90, 76, cyclic_prefix::NORMAL, {modulation_scheme::QPSK, 672.5}, {{0, ldpc_base_graph_type::BG1, true}}, {10, 0, csi_part2_size(0), 1, 20, 6.25, 6.25}, 672, 1, {0, 1, 2, 3}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 54081, 1, 2, rb_allocation::make_type1(4, 20), 0, 14, units::bytes(159749), 147}}, {"test_data/pusch_processor_test_input_grid20.dat"}, {"test_data/pusch_processor_test_tb20.dat"}, {"test_data/pusch_processor_test_harq20.dat"}, {"test_data/pusch_processor_test_csi120.dat"}, {"test_data/pusch_processor_test_csi220.dat"}},
  {{139, 14, {std::nullopt, {0, 7}, 64559, 102, 37, cyclic_prefix::NORMAL, {modulation_scheme::QPSK, 670.7}, {{0, ldpc_base_graph_type::BG1, true}}, {10, 4, csi_part2_size(0), 1, 20, 6.25, 6.25}, 561, 1, {0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 29399, 0, 2, rb_allocation::make_type1(52, 21), 0, 14, units::bytes(159749), 796}}, {"test_data/pusch_processor_test_input_grid21.dat"}, {"test_data/pusch_processor_test_tb21.dat"}, {"test_data/pusch_processor_test_harq21.dat"}, {"test_data/pusch_processor_test_csi121.dat"}, {"test_data/pusch_processor_test_csi221.dat"}},
  {{59, 14, {std::nullopt, {0, 1}, 954, 47, 12, cyclic_prefix::NORMAL, {modulation_scheme::QAM16, 133.2}, {{0, ldpc_base_graph_type::BG2, true}}, {10, 4, csi_part2_size(0), 1, 20, 6.25, 6.25}, 30, 1, {0, 1}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 24382, 0, 2, rb_allocation::make_type1(3, 25), 0, 14, units::bytes(159749), 320}}, {"test_data/pusch_processor_test_input_grid22.dat"}, {"test_data/pusch_processor_test_tb22.dat"}, {"test_data/pusch_processor_test_harq22.dat"}, {"test_data/pusch_processor_test_csi122.dat"}, {"test_data/pusch_processor_test_csi222.dat"}},
  {{272, 14, {std::nullopt, {0, 7}, 65180, 20, 252, cyclic_prefix::NORMAL, {modulation_scheme::QAM64, 448}, {{0, ldpc_base_graph_type::BG1, true}}, {10, 4, csi_part2_size(0), 1, 20, 6.25, 6.25}, 583, 1, {0, 1, 2, 3}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 41316, 0, 2, rb_allocation::make_type1(4, 16), 0, 14, units::bytes(159749), 428}}, {"test_data/pusch_processor_test_input_grid23.dat"}, {"test_data/pusch_processor_test_tb23.dat"}, {"test_data/pusch_processor_test_harq23.dat"}, {"test_data/pusch_processor_test_csi123.dat"}, {"test_data/pusch_processor_test_csi223.dat"}},
  {{266, 14, {std::nullopt, {0, 3}, 29028, 90, 176, cyclic_prefix::NORMAL, {modulation_scheme::QAM16, 515.6}, {{0, ldpc_base_graph_type::BG1, true}}, {10, 5, csi_part2_size(1), 1, 20, 6.25, 6.25}, 951, 1, {0}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 40660, 1, 2, rb_allocation::make_type1(20, 19), 0, 14, units::bytes(159749), 483}}, {"test_data/pusch_processor_test_input_grid24.dat"}, {"test_data/pusch_processor_test_tb24.dat"}, {"test_data/pusch_processor_test_harq24.dat"}, {"test_data/pusch_processor_test_csi124.dat"}, {"test_data/pusch_processor_test_csi224.dat"}},
  {{222, 14, {std::nullopt, {0, 7}, 13563, 135, 87, cyclic_prefix::NORMAL, {modulation_scheme::QAM16, 601.8}, {{0, ldpc_base_graph_type::BG1, true}}, {10, 5, csi_part2_size(1), 1, 20, 6.25, 6.25}, 75, 1, {0, 1}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 59544, 0, 2, rb_allocation::make_type1(25, 19), 0, 14, units::bytes(159749), 549}}, {"test_data/pusch_processor_test_input_grid25.dat"}, {"test_data/pusch_processor_test_tb25.dat"}, {"test_data/pusch_processor_test_harq25.dat"}, {"test_data/pusch_processor_test_csi125.dat"}, {"test_data/pusch_processor_test_csi225.dat"}},
  {{187, 14, {std::nullopt, {0, 7}, 27683, 19, 168, cyclic_prefix::NORMAL, {modulation_scheme::QPSK, 624.4}, {{0, ldpc_base_graph_type::BG2, true}}, {10, 5, csi_part2_size(1), 1, 20, 6.25, 6.25}, 268, 1, {0, 1, 2, 3}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 17324, 1, 2, rb_allocation::make_type1(2, 17), 0, 14, units::bytes(159749), 389}}, {"test_data/pusch_processor_test_input_grid26.dat"}, {"test_data/pusch_processor_test_tb26.dat"}, {"test_data/pusch_processor_test_harq26.dat"}, {"test_data/pusch_processor_test_csi126.dat"}, {"test_data/pusch_processor_test_csi226.dat"}},
    // clang-format on
};

} // namespace srsran