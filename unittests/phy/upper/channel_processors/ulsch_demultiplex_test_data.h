/*
 *
 * Copyright 2013-2022 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#pragma once

// This file was generated using the following MATLAB class on 02-Nov-2022:
//   + "srsULSCHDemultiplexUnittest.m"

#include "srsgnb/phy/upper/channel_processors/ulsch_demultiplex.h"
#include "srsgnb/phy/upper/log_likelihood_ratio.h"
#include "srsgnb/support/file_vector.h"

namespace srsgnb {

struct test_case_context {
  ulsch_demultiplex::configuration       config;
  ulsch_demultiplex::message_information msg_info;
};

struct test_case_t {
  test_case_context                 context;
  file_vector<log_likelihood_ratio> input;
  file_vector<log_likelihood_ratio> output_ulsch;
  file_vector<log_likelihood_ratio> output_harq_ack;
  file_vector<log_likelihood_ratio> output_csi_part1;
  file_vector<log_likelihood_ratio> output_csi_part2;
  file_vector<uint16_t>             placeholders;
};

static const std::vector<test_case_t> ulsch_demultiplex_test_data = {
    // clang-format off
  {{{modulation_scheme::PI_2_BPSK, 4, 14, 0, 14, 132, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 2}, {0, 0, 0, 0, 0, 0}}, {"test_data/ulsch_demultiplex_test_input0.dat"}, {"test_data/ulsch_demultiplex_test_data0.dat"}, {"test_data/ulsch_demultiplex_test_harq0.dat"}, {"test_data/ulsch_demultiplex_test_csi10.dat"}, {"test_data/ulsch_demultiplex_test_csi20.dat"}, {"test_data/ulsch_demultiplex_test_placeholders0.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 3, 2, 0, 14, 57, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 3}, {0, 0, 0, 0, 1, 9}}, {"test_data/ulsch_demultiplex_test_input1.dat"}, {"test_data/ulsch_demultiplex_test_data1.dat"}, {"test_data/ulsch_demultiplex_test_harq1.dat"}, {"test_data/ulsch_demultiplex_test_csi11.dat"}, {"test_data/ulsch_demultiplex_test_csi21.dat"}, {"test_data/ulsch_demultiplex_test_placeholders1.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 2, 11, 0, 14, 62, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 3}, {0, 0, 1, 10, 0, 0}}, {"test_data/ulsch_demultiplex_test_input2.dat"}, {"test_data/ulsch_demultiplex_test_data2.dat"}, {"test_data/ulsch_demultiplex_test_harq2.dat"}, {"test_data/ulsch_demultiplex_test_csi12.dat"}, {"test_data/ulsch_demultiplex_test_csi22.dat"}, {"test_data/ulsch_demultiplex_test_placeholders2.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 4, 10, 0, 14, 132, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 3}, {0, 0, 1, 24, 1, 24}}, {"test_data/ulsch_demultiplex_test_input3.dat"}, {"test_data/ulsch_demultiplex_test_data3.dat"}, {"test_data/ulsch_demultiplex_test_harq3.dat"}, {"test_data/ulsch_demultiplex_test_csi13.dat"}, {"test_data/ulsch_demultiplex_test_csi23.dat"}, {"test_data/ulsch_demultiplex_test_placeholders3.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 4, 6, 0, 14, 56, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 2}, {0, 0, 4, 36, 0, 0}}, {"test_data/ulsch_demultiplex_test_input4.dat"}, {"test_data/ulsch_demultiplex_test_data4.dat"}, {"test_data/ulsch_demultiplex_test_harq4.dat"}, {"test_data/ulsch_demultiplex_test_csi14.dat"}, {"test_data/ulsch_demultiplex_test_csi24.dat"}, {"test_data/ulsch_demultiplex_test_placeholders4.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 3, 9, 0, 14, 66, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 3}, {0, 0, 4, 42, 1, 12}}, {"test_data/ulsch_demultiplex_test_input5.dat"}, {"test_data/ulsch_demultiplex_test_data5.dat"}, {"test_data/ulsch_demultiplex_test_harq5.dat"}, {"test_data/ulsch_demultiplex_test_csi15.dat"}, {"test_data/ulsch_demultiplex_test_csi25.dat"}, {"test_data/ulsch_demultiplex_test_placeholders5.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 3, 13, 0, 14, 96, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 2}, {1, 48, 0, 0, 0, 0}}, {"test_data/ulsch_demultiplex_test_input6.dat"}, {"test_data/ulsch_demultiplex_test_data6.dat"}, {"test_data/ulsch_demultiplex_test_harq6.dat"}, {"test_data/ulsch_demultiplex_test_csi16.dat"}, {"test_data/ulsch_demultiplex_test_csi26.dat"}, {"test_data/ulsch_demultiplex_test_placeholders6.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 4, 8, 0, 14, 64, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 3}, {1, 32, 0, 0, 1, 12}}, {"test_data/ulsch_demultiplex_test_input7.dat"}, {"test_data/ulsch_demultiplex_test_data7.dat"}, {"test_data/ulsch_demultiplex_test_harq7.dat"}, {"test_data/ulsch_demultiplex_test_csi17.dat"}, {"test_data/ulsch_demultiplex_test_csi27.dat"}, {"test_data/ulsch_demultiplex_test_placeholders7.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 3, 13, 0, 14, 42, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 3}, {1, 21, 1, 9, 0, 0}}, {"test_data/ulsch_demultiplex_test_input8.dat"}, {"test_data/ulsch_demultiplex_test_data8.dat"}, {"test_data/ulsch_demultiplex_test_harq8.dat"}, {"test_data/ulsch_demultiplex_test_csi18.dat"}, {"test_data/ulsch_demultiplex_test_csi28.dat"}, {"test_data/ulsch_demultiplex_test_placeholders8.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 1, 7, 0, 14, 66, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 1}, {1, 33, 1, 11, 1, 11}}, {"test_data/ulsch_demultiplex_test_input9.dat"}, {"test_data/ulsch_demultiplex_test_data9.dat"}, {"test_data/ulsch_demultiplex_test_harq9.dat"}, {"test_data/ulsch_demultiplex_test_csi19.dat"}, {"test_data/ulsch_demultiplex_test_csi29.dat"}, {"test_data/ulsch_demultiplex_test_placeholders9.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 4, 14, 0, 14, 64, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 2}, {1, 32, 4, 40, 0, 0}}, {"test_data/ulsch_demultiplex_test_input10.dat"}, {"test_data/ulsch_demultiplex_test_data10.dat"}, {"test_data/ulsch_demultiplex_test_harq10.dat"}, {"test_data/ulsch_demultiplex_test_csi110.dat"}, {"test_data/ulsch_demultiplex_test_csi210.dat"}, {"test_data/ulsch_demultiplex_test_placeholders10.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 4, 15, 0, 14, 48, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 3}, {1, 24, 4, 32, 1, 8}}, {"test_data/ulsch_demultiplex_test_input11.dat"}, {"test_data/ulsch_demultiplex_test_data11.dat"}, {"test_data/ulsch_demultiplex_test_harq11.dat"}, {"test_data/ulsch_demultiplex_test_csi111.dat"}, {"test_data/ulsch_demultiplex_test_csi211.dat"}, {"test_data/ulsch_demultiplex_test_placeholders11.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 2, 7, 0, 14, 0, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 2}, {4, 182, 0, 0, 0, 0}}, {"test_data/ulsch_demultiplex_test_input12.dat"}, {"test_data/ulsch_demultiplex_test_data12.dat"}, {"test_data/ulsch_demultiplex_test_harq12.dat"}, {"test_data/ulsch_demultiplex_test_csi112.dat"}, {"test_data/ulsch_demultiplex_test_csi212.dat"}, {"test_data/ulsch_demultiplex_test_placeholders12.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 3, 11, 0, 14, 0, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 3}, {4, 624, 0, 0, 1, 51}}, {"test_data/ulsch_demultiplex_test_input13.dat"}, {"test_data/ulsch_demultiplex_test_data13.dat"}, {"test_data/ulsch_demultiplex_test_harq13.dat"}, {"test_data/ulsch_demultiplex_test_csi113.dat"}, {"test_data/ulsch_demultiplex_test_csi213.dat"}, {"test_data/ulsch_demultiplex_test_placeholders13.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 1, 1, 0, 14, 0, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 1}, {4, 88, 1, 7, 0, 0}}, {"test_data/ulsch_demultiplex_test_input14.dat"}, {"test_data/ulsch_demultiplex_test_data14.dat"}, {"test_data/ulsch_demultiplex_test_harq14.dat"}, {"test_data/ulsch_demultiplex_test_csi114.dat"}, {"test_data/ulsch_demultiplex_test_csi214.dat"}, {"test_data/ulsch_demultiplex_test_placeholders14.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 4, 7, 0, 14, 0, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 3}, {4, 104, 1, 8, 1, 8}}, {"test_data/ulsch_demultiplex_test_input15.dat"}, {"test_data/ulsch_demultiplex_test_data15.dat"}, {"test_data/ulsch_demultiplex_test_harq15.dat"}, {"test_data/ulsch_demultiplex_test_csi115.dat"}, {"test_data/ulsch_demultiplex_test_csi215.dat"}, {"test_data/ulsch_demultiplex_test_placeholders15.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 1, 2, 0, 14, 0, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 1}, {4, 84, 4, 26, 0, 0}}, {"test_data/ulsch_demultiplex_test_input16.dat"}, {"test_data/ulsch_demultiplex_test_data16.dat"}, {"test_data/ulsch_demultiplex_test_harq16.dat"}, {"test_data/ulsch_demultiplex_test_csi116.dat"}, {"test_data/ulsch_demultiplex_test_csi216.dat"}, {"test_data/ulsch_demultiplex_test_placeholders16.dat"}},
  {{{modulation_scheme::PI_2_BPSK, 4, 6, 0, 14, 0, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 2}, {4, 124, 4, 40, 1, 12}}, {"test_data/ulsch_demultiplex_test_input17.dat"}, {"test_data/ulsch_demultiplex_test_data17.dat"}, {"test_data/ulsch_demultiplex_test_harq17.dat"}, {"test_data/ulsch_demultiplex_test_csi117.dat"}, {"test_data/ulsch_demultiplex_test_csi217.dat"}, {"test_data/ulsch_demultiplex_test_placeholders17.dat"}},
  {{{modulation_scheme::QAM16, 2, 14, 0, 14, 48, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 3}, {0, 0, 0, 0, 0, 0}}, {"test_data/ulsch_demultiplex_test_input18.dat"}, {"test_data/ulsch_demultiplex_test_data18.dat"}, {"test_data/ulsch_demultiplex_test_harq18.dat"}, {"test_data/ulsch_demultiplex_test_csi118.dat"}, {"test_data/ulsch_demultiplex_test_csi218.dat"}, {"test_data/ulsch_demultiplex_test_placeholders18.dat"}},
  {{{modulation_scheme::QAM16, 4, 2, 0, 14, 96, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 3}, {0, 0, 0, 0, 1, 16}}, {"test_data/ulsch_demultiplex_test_input19.dat"}, {"test_data/ulsch_demultiplex_test_data19.dat"}, {"test_data/ulsch_demultiplex_test_harq19.dat"}, {"test_data/ulsch_demultiplex_test_csi119.dat"}, {"test_data/ulsch_demultiplex_test_csi219.dat"}, {"test_data/ulsch_demultiplex_test_placeholders19.dat"}},
  {{{modulation_scheme::QAM16, 3, 7, 0, 14, 108, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 3}, {0, 0, 1, 24, 0, 0}}, {"test_data/ulsch_demultiplex_test_input20.dat"}, {"test_data/ulsch_demultiplex_test_data20.dat"}, {"test_data/ulsch_demultiplex_test_harq20.dat"}, {"test_data/ulsch_demultiplex_test_csi120.dat"}, {"test_data/ulsch_demultiplex_test_csi220.dat"}, {"test_data/ulsch_demultiplex_test_placeholders20.dat"}},
  {{{modulation_scheme::QAM16, 4, 13, 0, 14, 48, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 3}, {0, 0, 1, 16, 1, 16}}, {"test_data/ulsch_demultiplex_test_input21.dat"}, {"test_data/ulsch_demultiplex_test_data21.dat"}, {"test_data/ulsch_demultiplex_test_harq21.dat"}, {"test_data/ulsch_demultiplex_test_csi121.dat"}, {"test_data/ulsch_demultiplex_test_csi221.dat"}, {"test_data/ulsch_demultiplex_test_placeholders21.dat"}},
  {{{modulation_scheme::QAM16, 3, 6, 0, 14, 60, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 3}, {0, 0, 4, 36, 0, 0}}, {"test_data/ulsch_demultiplex_test_input22.dat"}, {"test_data/ulsch_demultiplex_test_data22.dat"}, {"test_data/ulsch_demultiplex_test_harq22.dat"}, {"test_data/ulsch_demultiplex_test_csi122.dat"}, {"test_data/ulsch_demultiplex_test_csi222.dat"}, {"test_data/ulsch_demultiplex_test_placeholders22.dat"}},
  {{{modulation_scheme::QAM16, 3, 4, 0, 14, 72, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 3}, {0, 0, 4, 48, 1, 12}}, {"test_data/ulsch_demultiplex_test_input23.dat"}, {"test_data/ulsch_demultiplex_test_data23.dat"}, {"test_data/ulsch_demultiplex_test_harq23.dat"}, {"test_data/ulsch_demultiplex_test_csi123.dat"}, {"test_data/ulsch_demultiplex_test_csi223.dat"}, {"test_data/ulsch_demultiplex_test_placeholders23.dat"}},
  {{{modulation_scheme::QAM16, 2, 3, 0, 14, 72, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 3}, {1, 40, 0, 0, 0, 0}}, {"test_data/ulsch_demultiplex_test_input24.dat"}, {"test_data/ulsch_demultiplex_test_data24.dat"}, {"test_data/ulsch_demultiplex_test_harq24.dat"}, {"test_data/ulsch_demultiplex_test_csi124.dat"}, {"test_data/ulsch_demultiplex_test_csi224.dat"}, {"test_data/ulsch_demultiplex_test_placeholders24.dat"}},
  {{{modulation_scheme::QAM16, 2, 7, 0, 14, 72, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 2}, {1, 40, 0, 0, 1, 16}}, {"test_data/ulsch_demultiplex_test_input25.dat"}, {"test_data/ulsch_demultiplex_test_data25.dat"}, {"test_data/ulsch_demultiplex_test_harq25.dat"}, {"test_data/ulsch_demultiplex_test_csi125.dat"}, {"test_data/ulsch_demultiplex_test_csi225.dat"}, {"test_data/ulsch_demultiplex_test_placeholders25.dat"}},
  {{{modulation_scheme::QAM16, 4, 8, 0, 14, 48, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 2}, {1, 32, 1, 16, 0, 0}}, {"test_data/ulsch_demultiplex_test_input26.dat"}, {"test_data/ulsch_demultiplex_test_data26.dat"}, {"test_data/ulsch_demultiplex_test_harq26.dat"}, {"test_data/ulsch_demultiplex_test_csi126.dat"}, {"test_data/ulsch_demultiplex_test_csi226.dat"}, {"test_data/ulsch_demultiplex_test_placeholders26.dat"}},
  {{{modulation_scheme::QAM16, 2, 15, 0, 14, 64, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 3}, {1, 32, 1, 16, 1, 16}}, {"test_data/ulsch_demultiplex_test_input27.dat"}, {"test_data/ulsch_demultiplex_test_data27.dat"}, {"test_data/ulsch_demultiplex_test_harq27.dat"}, {"test_data/ulsch_demultiplex_test_csi127.dat"}, {"test_data/ulsch_demultiplex_test_csi227.dat"}, {"test_data/ulsch_demultiplex_test_placeholders27.dat"}},
  {{{modulation_scheme::QAM16, 4, 8, 0, 14, 48, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 2}, {1, 32, 4, 32, 0, 0}}, {"test_data/ulsch_demultiplex_test_input28.dat"}, {"test_data/ulsch_demultiplex_test_data28.dat"}, {"test_data/ulsch_demultiplex_test_harq28.dat"}, {"test_data/ulsch_demultiplex_test_csi128.dat"}, {"test_data/ulsch_demultiplex_test_csi228.dat"}, {"test_data/ulsch_demultiplex_test_placeholders28.dat"}},
  {{{modulation_scheme::QAM16, 2, 3, 0, 14, 64, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 2}, {1, 32, 4, 40, 1, 16}}, {"test_data/ulsch_demultiplex_test_input29.dat"}, {"test_data/ulsch_demultiplex_test_data29.dat"}, {"test_data/ulsch_demultiplex_test_harq29.dat"}, {"test_data/ulsch_demultiplex_test_csi129.dat"}, {"test_data/ulsch_demultiplex_test_csi229.dat"}, {"test_data/ulsch_demultiplex_test_placeholders29.dat"}},
  {{{modulation_scheme::QAM16, 2, 4, 0, 14, 0, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 2}, {4, 88, 0, 0, 0, 0}}, {"test_data/ulsch_demultiplex_test_input30.dat"}, {"test_data/ulsch_demultiplex_test_data30.dat"}, {"test_data/ulsch_demultiplex_test_harq30.dat"}, {"test_data/ulsch_demultiplex_test_csi130.dat"}, {"test_data/ulsch_demultiplex_test_csi230.dat"}, {"test_data/ulsch_demultiplex_test_placeholders30.dat"}},
  {{{modulation_scheme::QAM16, 3, 7, 0, 14, 0, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 2}, {4, 156, 0, 0, 1, 12}}, {"test_data/ulsch_demultiplex_test_input31.dat"}, {"test_data/ulsch_demultiplex_test_data31.dat"}, {"test_data/ulsch_demultiplex_test_harq31.dat"}, {"test_data/ulsch_demultiplex_test_csi131.dat"}, {"test_data/ulsch_demultiplex_test_csi231.dat"}, {"test_data/ulsch_demultiplex_test_placeholders31.dat"}},
  {{{modulation_scheme::QAM16, 2, 3, 0, 14, 0, dmrs_type::TYPE2, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 3}, {4, 320, 1, 32, 0, 0}}, {"test_data/ulsch_demultiplex_test_input32.dat"}, {"test_data/ulsch_demultiplex_test_data32.dat"}, {"test_data/ulsch_demultiplex_test_harq32.dat"}, {"test_data/ulsch_demultiplex_test_csi132.dat"}, {"test_data/ulsch_demultiplex_test_csi232.dat"}, {"test_data/ulsch_demultiplex_test_placeholders32.dat"}},
  {{{modulation_scheme::QAM16, 4, 8, 0, 14, 0, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 2}, {4, 272, 1, 32, 1, 32}}, {"test_data/ulsch_demultiplex_test_input33.dat"}, {"test_data/ulsch_demultiplex_test_data33.dat"}, {"test_data/ulsch_demultiplex_test_harq33.dat"}, {"test_data/ulsch_demultiplex_test_csi133.dat"}, {"test_data/ulsch_demultiplex_test_csi233.dat"}, {"test_data/ulsch_demultiplex_test_placeholders33.dat"}},
  {{{modulation_scheme::QAM16, 2, 11, 0, 14, 0, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 2}, {4, 96, 4, 32, 0, 0}}, {"test_data/ulsch_demultiplex_test_input34.dat"}, {"test_data/ulsch_demultiplex_test_data34.dat"}, {"test_data/ulsch_demultiplex_test_harq34.dat"}, {"test_data/ulsch_demultiplex_test_csi134.dat"}, {"test_data/ulsch_demultiplex_test_csi234.dat"}, {"test_data/ulsch_demultiplex_test_placeholders34.dat"}},
  {{{modulation_scheme::QAM16, 2, 8, 0, 14, 0, dmrs_type::TYPE1, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 2}, {4, 104, 4, 32, 1, 8}}, {"test_data/ulsch_demultiplex_test_input35.dat"}, {"test_data/ulsch_demultiplex_test_data35.dat"}, {"test_data/ulsch_demultiplex_test_harq35.dat"}, {"test_data/ulsch_demultiplex_test_csi135.dat"}, {"test_data/ulsch_demultiplex_test_csi235.dat"}, {"test_data/ulsch_demultiplex_test_placeholders35.dat"}},
    // clang-format on
};

} // namespace srsgnb
