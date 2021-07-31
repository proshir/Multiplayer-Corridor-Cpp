#ifndef __SERVER_CONFIG_H_Z4NKUGO5BGRP__
#define __SERVER_CONFIG_H_Z4NKUGO5BGRP__

///////////////////////////////////////////////////////////
/// @brief ServerConfig
///
#include <iostream>
using namespace std;
class HttpServerCorridor;
class ServerConfig
{
    friend class HttpServerCorridor;
public:
    ServerConfig(string ,string,int ,int,pair<int,int>);
private:
    const string serverName;
    const string address;
    const int port;
    const int maxPlayers;
    const pair<int,int> gameSize;
};

#endif  // __SERVER_CONFIG_H_Z4NKUGO5BGRP__
