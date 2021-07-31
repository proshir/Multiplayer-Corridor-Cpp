#ifndef __HTTP_CLIENT_CORRIDOR_H_ORX3DNKXNOVL__
#define __HTTP_CLIENT_CORRIDOR_H_ORX3DNKXNOVL__

///////////////////////////////////////////////////////////
/// @brief HttpClientCorridor
///
#include "ClientLibs/ConsoleWork.h"
#include "ClientLibs/httplib.h"
#include "Utility.cpp"
using namespace httplib;
class HttpClientCorridor
{
public:
    HttpClientCorridor();
    void InitConnectConfigFromConsole();
    void InitClient();
    bool JoinToServer(string);
    bool InitStatusCore(string,string apiReady,string apiTurn);
    void SendReady(string);
    void GetTurn(string);
    
private:
    ConnectConfig* connectConfig;
    ConsoleWork* consoleWork;
    Client* client;
};

#endif  // __HTTP_CLIENT_CORRIDOR_H_ORX3DNKXNOVL__
