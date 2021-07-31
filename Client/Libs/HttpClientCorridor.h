#ifndef __HTTP_CLIENT_CORRIDOR_H_ORX3DNKXNOVL__
#define __HTTP_CLIENT_CORRIDOR_H_ORX3DNKXNOVL__

///////////////////////////////////////////////////////////
/// @brief HttpClientCorridor
///
#include "ClientLibs/ConsoleWork.h"
class HttpClientCorridor
{
public:
    HttpClientCorridor();
    void InitConnectConfigFromConsole();
private:
    ConnectConfig* connectConfig;
    ConsoleWork* consoleWork;
};

#endif  // __HTTP_CLIENT_CORRIDOR_H_ORX3DNKXNOVL__
