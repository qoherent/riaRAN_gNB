#ifndef ADAPTERS_H
#define ADAPTERS_H

#include "srsgnb/F1_interface/F1u.h"
#include "srsgnb/pdcp/pdcp.h"
#include "srsgnb/sdap/sdap.h"
#include <cstdio>

namespace cu_up {

/// These adapters glue two network layers to establish a communication between them. With this pattern, each layer is
/// decoupled from the other.
/// This is necessary when the F1u interface is not required (no CU/DU split) and the RLC forwards packets directly to
/// the PDCP. In this case we would create a RLC-PDCP adapter following the same idea as done here, without having to
/// touch a single line of code of the RLC or PDCP layers. They are agnostic to the deployment scenario.

/// Adapter interface from PDCP to SDAP.
class sdap_packet_handler : public srsgnb::pdcp_packet_notifier
{
  srsgnb::sdap_input_gateway& sdap;

public:
  explicit sdap_packet_handler(srsgnb::sdap_input_gateway& sdap) : sdap(sdap) {}

  void on_new_packet(srsgnb::byte_buffer& data) override
  {
    std::printf("[PDCP-SDAP-ADAPTER] Received a packet from PDCP layer, forwarding data packet of size = %u bytes to "
                "upper layer (SDAP)\n",
                (unsigned)data.size());
    sdap.handle(data);
  }
};

/// Adapter interface from F1u to PDCP.
class pdcp_packet_handler : public srsgnb::F1u_packet_notifier
{
  srsgnb::pdcp_input_gateway& pdcp;

public:
  explicit pdcp_packet_handler(srsgnb::pdcp_input_gateway& pdcp) : pdcp(pdcp) {}

  void on_new_packet(srsgnb::byte_buffer& data) override
  {
    std::printf("[F1u-PDCP-ADAPTER] Received a packet from F1u layer, forwarding data packet of size = %u bytes to "
                "upper layer (PDCP)\n",
                (unsigned)data.size());
    pdcp.handle(data);
  }
};

} // namespace cu_up

#endif // ADAPTERS_H
