/*
 *
 * Copyright 2021-2023 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#pragma once

#include "srsran/ru/ru_generic_configuration.h"

namespace srsran {

/// \brief Helper function that validates the pointer members of the given Radio Unit configuration. Returns true on
/// success, otherwise false.
///
/// The pointers to baseband gateway, rx symbol notifier, timing notifier and error notifier are not being checked as
/// the Radio Unit factory still needs to create the adapters and set them in the lower PHY configuration.
bool is_valid(const ru_generic_configuration& config)
{
  if (!config.symbol_notifier) {
    return false;
  }

  if (!config.timing_notifier) {
    return false;
  }

  if (!config.rf_logger) {
    return false;
  }

  if (!config.radio_exec) {
    return false;
  }

  if (!config.lower_phy_config.rx_task_executor) {
    return false;
  }

  if (!config.lower_phy_config.tx_task_executor) {
    return false;
  }

  if (!config.lower_phy_config.dl_task_executor) {
    return false;
  }

  if (!config.lower_phy_config.ul_task_executor) {
    return false;
  }

  if (!config.lower_phy_config.prach_async_executor) {
    return false;
  }

  return true;
}

} // namespace srsran
