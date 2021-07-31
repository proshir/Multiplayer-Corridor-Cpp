#ifndef __CONNECT_CONFIG_H_CXDDSMQBPSE9__
#define __CONNECT_CONFIG_H_CXDDSMQBPSE9__

///////////////////////////////////////////////////////////
/// @brief ConnectConfig
///
#include <iostream>
using namespace std;
class HttpClientCorridor;
class ConnectConfig
{
    friend class HttpClientCorridor;
public:
    ConnectConfig(string _name,string _address,int _port);
private:
    const string name;
    const string address;
    const int port;
    int id;
};

#endif  // __CONNECT_CONFIG_H_CXDDSMQBPSE9__
