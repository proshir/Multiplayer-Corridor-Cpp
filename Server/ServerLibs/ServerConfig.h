#ifndef __SERVER_CONFIG_H_Z4NKUGO5BGRP__
#define __SERVER_CONFIG_H_Z4NKUGO5BGRP__

///////////////////////////////////////////////////////////
/// @brief ServerConfig
///
#include <iostream>
using namespace std;
class ServerConfig
{
public:
    ServerConfig(string ,string,int ,int );
    const string serverName;
    const string address;
    const int port;
    const int maxPlayers;
};

#endif  // __SERVER_CONFIG_H_Z4NKUGO5BGRP__
