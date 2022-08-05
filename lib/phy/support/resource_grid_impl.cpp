/*
 *
 * Copyright 2013-2022 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#include "resource_grid_impl.h"
#include "srsgnb/phy/support/support_factories.h"
#include "srsgnb/srsvec/copy.h"
#include "srsgnb/srsvec/zero.h"
#include "srsgnb/support/error_handling.h"
#include "srsgnb/support/srsgnb_assert.h"
#include <cassert>

using namespace srsgnb;

resource_grid_impl::resource_grid_impl(unsigned nof_ports_, unsigned nof_symb_, unsigned nof_subc_) :
  empty(nof_ports_), nof_ports(nof_ports_), nof_symb(nof_symb_), nof_subc(nof_subc_), port_buffers(nof_ports)
{
  // For each port allocate buffer
  for (auto& buffer : port_buffers) {
    buffer.resize(nof_symb * nof_subc);
  }
}

void resource_grid_impl::put(unsigned port, span<const resource_grid_coordinate> coordinates, span<const cf_t> symbols)
{
  srsgnb_assert(coordinates.size() == symbols.size(),
                "The number of coordinates {} is not equal to the number of symbols {}.",
                coordinates.size(),
                symbols.size());

  // Select buffer from the port index
  srsgnb_assert(port < nof_ports, "The port index {} is out of range (max {}).", port, nof_ports - 1);
  span<cf_t> buffer = port_buffers[port];

  unsigned count = 0;
  for (const resource_grid_coordinate& coordinate : coordinates) {
    srsgnb_assert(
        coordinate.symbol < nof_symb, "Symbol index {} is out of range (max {}).", coordinate.symbol, nof_symb);
    srsgnb_assert(coordinate.subcarrier < nof_subc,
                  "Subcarrier index {} is out of range (max {}).",
                  coordinate.subcarrier,
                  nof_subc);
    buffer[coordinate.symbol * nof_subc + coordinate.subcarrier] = symbols[count++];
  }
  empty[port] = false;
}

span<const cf_t> resource_grid_impl::put(unsigned         port,
                                         unsigned         l,
                                         unsigned         k_init,
                                         span<const bool> mask,
                                         span<const cf_t> symbol_buffer)
{
  assert(l < nof_symb);
  assert(mask.size() <= nof_subc);

  // Select buffer from the port index
  assert(port < nof_ports);
  span<cf_t> buffer = port_buffers[port];

  // Select destination symbol in buffer
  span<cf_t> symb = buffer.subspan(l * nof_subc, nof_subc);

  // Iterate mask
  unsigned count = 0;
  for (unsigned k = 0; k != mask.size(); ++k) {
    if (mask[k]) {
      symb[k + k_init] = symbol_buffer[count];
      count++;
    }
  }
  empty[port] = false;

  // Update symbol buffer
  return symbol_buffer.last(symbol_buffer.size() - count);
}
void resource_grid_impl::put(unsigned port, unsigned l, unsigned k_init, span<const cf_t> symbols)
{
  report_fatal_error_if_not(l < nof_symb, "Symbol index ({}) is out-of-range (max. {})", l, nof_symb);
  report_fatal_error_if_not(k_init + symbols.size() <= nof_subc,
                            "Subcarrier indexes ({},{}) are out-of-range (max. {})",
                            k_init,
                            symbols.size(),
                            nof_subc);
  report_fatal_error_if_not(port < nof_ports, "Port index ({}) is out-of-range (max. {})", port, nof_ports);

  // Select buffer from the port index
  span<cf_t> buffer = port_buffers[port];

  // Copy
  srsvec::copy(buffer.subspan(l * nof_subc + k_init, symbols.size()), symbols);
  empty[port] = false;
}
void resource_grid_impl::set_all_zero()
{
  // For each port buffer set to zero
  for (unsigned port = 0; port != nof_ports; ++port) {
    if (!empty[port]) {
      srsvec::zero(port_buffers[port]);
      empty[port] = true;
    }
  }
}

void resource_grid_impl::get(span<cf_t> symbols, unsigned port, span<const resource_grid_coordinate> coordinates) const
{
  assert(coordinates.size() == symbols.size());

  // Select buffer from the port index
  assert(port < nof_ports);
  span<const cf_t> buffer = port_buffers[port];

  cf_t* symbol_ptr = symbols.begin();
  for (const resource_grid_coordinate& coordinate : coordinates) {
    assert(coordinate.symbol < nof_symb);
    assert(coordinate.subcarrier < nof_subc);
    *(symbol_ptr++) = buffer[coordinate.symbol * nof_subc + coordinate.subcarrier];
  }
}

span<cf_t>
resource_grid_impl::get(span<cf_t> symbols, unsigned port, unsigned l, unsigned k_init, span<const bool> mask) const
{
  assert(l < nof_symb);
  assert(mask.size() <= nof_subc);

  // Select buffer from the port index
  assert(port < nof_ports);
  span<const cf_t> buffer = port_buffers[port];

  // Select destination symbol in buffer
  span<const cf_t> symb = buffer.subspan(l * nof_subc, nof_subc);

  // Iterate mask
  unsigned count = 0;
  for (unsigned k = 0; k != mask.size(); ++k) {
    if (mask[k]) {
      symbols[count] = symb[k + k_init];
      count++;
    }
  }

  // Update symbol buffer
  return symbols.last(symbols.size() - count);
}

void resource_grid_impl::get(span<cf_t> symbols, unsigned port, unsigned l, unsigned k_init) const
{
  assert(l < nof_symb);
  assert(k_init + symbols.size() <= nof_subc);

  // Select buffer from the port index
  assert(port < nof_ports);
  span<const cf_t> buffer = port_buffers[port];

  // Copy
  srsvec::copy(symbols, buffer.subspan(l * nof_subc + k_init, symbols.size()));
}

bool resource_grid_impl::is_empty(unsigned port) const
{
  srsgnb_assert(port < empty.size(), "Port index {} is out of range (max {})", port, empty.size());
  return empty[port];
}

std::unique_ptr<resource_grid> srsgnb::create_resource_grid(unsigned nof_ports, unsigned nof_symbols, unsigned nof_subc)
{
  return std::make_unique<resource_grid_impl>(nof_ports, nof_symbols, nof_subc);
}