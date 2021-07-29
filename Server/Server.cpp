#include<iostream>
#include "ServerLibs/ServerConfig.h"
#include "ServerLibs/ConsoleWork.h"
#include "ServerLibs/httplib.h"
#include "GameLibs/Player.h"
using namespace httplib;
int main()
{
    ServerConfig *serverConfig;
    ConsoleWork *consoleWork;
    consoleWork->GetServerConfig(serverConfig);
    Player** players=new Player* [serverConfig->maxPlayers];
    int playerConnected=0;
    Server svr;
    svr.Get("/connect", [&](const Request& req, Response& res) {
        if(playerConnected<serverConfig->maxPlayers)
        {
            if (req.has_header("name")) {
                string name = req.get_header_value("name");
                players[playerConnected]=new Player(name);
                res.set_header("id",to_string(playerConnected));
                res.status=200;
            }
            else res.status=402;
        }
        else res.status=501;
    });
    svr.listen(serverConfig->address.data(),serverConfig->port);
}
