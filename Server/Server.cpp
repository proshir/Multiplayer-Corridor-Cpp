#include "ServerLibs/ServerConfig.h"
#include "ServerLibs/ConsoleWork.h"
#include "GameLibs/Player.h"
#include "Utility.cpp"
int main()
{
    ServerConfig *serverConfig;
    ConsoleWork *consoleWork;
    bool gameStarted;
    consoleWork->GetServerConfig(serverConfig);
    Player** players=new Player* [serverConfig->maxPlayers];
    int playerConnected=0;
    int playerReady=0;
    int turn=0;
    Server svr;
    svr.Get("/connect", [&](const Request& req, Response& res) {
        try
        {
            if(playerConnected<serverConfig->maxPlayers)
            {
                if (req.has_header("name")) {
                    string name = req.get_header_value("name");
                    consoleWork->SayPlayerEntered(name,playerConnected);
                    players[playerConnected]=new Player(name,playerConnected);
                    res.set_header("id",to_string(playerConnected));
                    playerConnected++;
                    res.status=200;
                }
                else res.status=406;
            }
            else 
            { 
                res.status=410; 
                res.set_header("message","This server is full");
            }
        }
        catch(const std::exception& e)
        {
            res.status=500;
        }
    });
    svr.Get("/status",[&](const Request& req, Response& res) {
        try
        {
            int id=GetHeaderId(req);
            res.status=200;
            if(playerConnected==serverConfig->maxPlayers)
            {
                if(!gameStarted )
                {
                    if(!players[id]->ready)
                        res.set_header("order","ReqReady");
                    else res.status=404;
                }
                else
                {

                }
            }
        }
        catch(const std::exception& e)
        {
            res.status=500;
        }
    });
    svr.Get("/ready",[&](const Request& req, Response& res) {
        try
        {
            int id=GetHeaderId(req);
            res.status=200;
            if(!gameStarted && playerConnected==serverConfig->maxPlayers)
            {
                if(req.has_header("id"))
                {
                    if(!players[id]->ready)
                    {
                        players[id]->ready=1;
                        playerReady++;
                        consoleWork->SayPlayerReady(id);
                        if(playerReady==playerConnected)
                            gameStarted=true;
                        else 
                            res.set_header("message","Wait for other players");
                    }
                } 
                else res.status=404;
            }
        }
        catch(const std::exception& e)
        {
            res.status=500;
        }
    });
    svr.listen(serverConfig->address.data(),serverConfig->port);
}
