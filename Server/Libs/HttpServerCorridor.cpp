#include "HttpServerCorridor.h"

using namespace std;

HttpServerCorridor::HttpServerCorridor()
{
    consoleWork=new ConsoleWork();
    serverConfig=0;
    players=0;
    svr=new Server();
}
void HttpServerCorridor::InitServerConfigFromConsole()
{
    consoleWork->GetServerConfig(serverConfig);
}
void HttpServerCorridor::InitPlayers()
{
    players=new Player* [serverConfig->maxPlayers];
}
void HttpServerCorridor::InitConnectApi(string api)
{
    svr->Get(api, [&](const Request& req, Response& res) {
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
}
void HttpServerCorridor::InitStatusApi(string api)
{
    svr->Get("/status",[&](const Request& req, Response& res) {
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
}
void HttpServerCorridor::InitReadyApi(string api)
{
    svr->Get("/ready",[&](const Request& req, Response& res) {
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
}
void HttpServerCorridor::StartListen()
{
    consoleWork->SayServerRun();
    svr->listen(serverConfig->address.data(),serverConfig->port);
}
HttpServerCorridor::~HttpServerCorridor()
{
    if(!players){
        for(int i=0;i<serverConfig->maxPlayers;i++)
        {
            if(!players[i]) delete players[i];
        }
        delete players;
    }
    if(!serverConfig) delete serverConfig;
    if(!consoleWork) delete consoleWork;
    delete svr;
}