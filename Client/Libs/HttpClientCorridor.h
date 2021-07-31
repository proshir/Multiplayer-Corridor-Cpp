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
    HttpClientCorridor(string _apiConnect,string _apiStatus,string _apiReady,string _apiTurn);
    void InitConnectConfigFromConsole();
    void InitClient();
    bool JoinToServer();
    void InitStatus();
    bool InitStatusCore();
    void SendReady();
    void GetTurn();
    
private:
    ConnectConfig* connectConfig;
    ConsoleWork* consoleWork;
    Client* client;
    string apiConnect;
    string apiStatus;
    string apiReady;
    string apiTurn;
};

#endif  // __HTTP_CLIENT_CORRIDOR_H_ORX3DNKXNOVL__
