/**
 * Copyright (c) 2013-2017 Husarion Sp. z o.o.
 * Distributed under the MIT license.
 * For full terms see the file LICENSE.md.
 */

#ifndef _HNETWORK_H_
#define _HNETWORK_H_

#ifndef HNETWORK_LWIP
#define HNETWORK_LWIP
#endif

#include <hNetwork_base.h>

namespace hFramework {
class _Network {
    char localIp[16] = {0};
    friend class _hWifi;
public:

    bool isOnline() { return true; }
    bool resolveAddress(const char* hostname, IpAddress& out);
    std::unique_ptr<hTCPConnection> connect(InetAddress addr);
    std::unique_ptr<hTCPConnection> connect(const char* hostname, int port);
    std::unique_ptr<hUdpSocket> bindUdp(int port);
    const char* getLocalIp() { return localIp; }
};

extern _Network Network;
}
#endif
