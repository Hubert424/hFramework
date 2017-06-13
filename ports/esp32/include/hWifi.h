/**
 * Copyright (c) 2013-2017 Husarion Sp. z o.o.
 * Distributed under the MIT license.
 * For full terms see the file LICENSE.md.
 */

#ifndef _HWIFI_H_
#define _HWIFI_H_
#include "hNetwork.h"
#include <vector>

namespace hFramework {

struct NetworkConfig {
    const char* ssid = nullptr;
    const char* password = nullptr;
};

struct AccessPointConfig {
    const char* ssid = nullptr;
    const char* password = nullptr;
    int channel = 5;
    int maxConnections = 4;

    IpAddress ipAddress = IpAddress{0xc0a85701}; // 192.168.87.1;
    int netmask = 24;
    IpAddress dhcpFirstAddress = IpAddress{0xc0a8570a}; // 192.168.87.10
    int maxDhcpClients = 10;
};

struct ScannedNetwork {
    char ssid[32];
    bool isEncrypted;
    int quality;
};

class _hWifi {
public:
    _hWifi() {}

    void setupAP(const AccessPointConfig& config); //!< Creates access point specified by `config`. Returns immediately.
    void connect(const NetworkConfig& config); //!< Connects to a network specified by `config`. Returns immediately.
    void connect(const NetworkConfig* configs, int count); //!< Tries to connect to one of the networks specified by `configs`. Returns mmediately.

    bool scan(std::vector<ScannedNetwork>& networks);
};

extern _hWifi Wifi;
}

#endif
