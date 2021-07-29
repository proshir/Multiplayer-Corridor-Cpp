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
    ServerConfig(string _serverName="Server",int _port=3150,int _maxPlayers=2):serverName(_serverName),port(_port),maxPlayers(_maxPlayers){}
private:
    string serverName;
    int port;
    int maxPlayers;
};

#endif  // __SERVER_CONFIG_H_Z4NKUGO5BGRP__
