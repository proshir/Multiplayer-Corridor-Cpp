#ifndef __HTTP_SERVER_CORRIDOR_H_7JF0GV2WK7L2__
#define __HTTP_SERVER_CORRIDOR_H_7JF0GV2WK7L2__

///////////////////////////////////////////////////////////
/// @brief HttpServerCorridor
///
#include "ServerLibs/ServerConfig.h"
#include "ServerLibs/ConsoleWork.h"
#include "GameLibs/Player.h"
#include "GameLibs/MapGame.h"
#include "Utility.cpp"
class HttpServerCorridor
{
public:
    HttpServerCorridor();
    void InitServerConfigFromConsole();
    void InitPlayers();
    void InitMapGame();
    void InitConnectApi(string);
    void InitStatusApi(string);
    void InitReadyApi(string);
    void InitTurnApi(string);
    void StartListen();
    ~HttpServerCorridor();
private:
    ServerConfig *serverConfig;
    ConsoleWork *consoleWork;
    Player** players;
    MapGame *mapGame;
    int playerConnected;
    int playerReady;
    int gameEnd;
    bool gameStarted;
    int turn;
    Server *svr;
};

#endif  // __HTTP_SERVER_CORRIDOR_H_7JF0GV2WK7L2__
