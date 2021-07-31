#include "HttpServerCorridor.h"
using namespace std;

HttpServerCorridor::HttpServerCorridor()
{
    consoleWork=new ConsoleWork();
    serverConfig=0;
    mapGame=0;
    players=0;
    gameStarted=0;
    gameEnd=0;
    svr=new Server();
}
void HttpServerCorridor::InitServerConfigFromConsole()
{
    consoleWork->GetServerConfig(serverConfig);
}
void HttpServerCorridor::InitMapGame()
{
    if(serverConfig)
        mapGame=new MapGame(serverConfig->gameSize);
}
void HttpServerCorridor::InitPlayers()
{
    players=new Player*[serverConfig->maxPlayers];
}
void HttpServerCorridor::InitConnectApi(string api)
{
    svr->Get(api, [&](const Request& req, Response& res) {
        
        try
        {
            
            if(playerConnected<serverConfig->maxPlayers)
            {
                string name=GetValHeader(req,"name");
                players[playerConnected]=new Player(name,playerConnected);
                mapGame->SetPlayerPos(players[playerConnected]->pos,playerConnected);
                res.set_header("id",to_string(playerConnected));
                consoleWork->SayPlayerEntered(name,playerConnected);
                playerConnected++;
                res.status=200;
            }
            else 
            { 
                res.status=510; 
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
    svr->Get(api,[&](const Request& req, Response& res) {
        try
        {
            int id=GetHeaderId(req,serverConfig->maxPlayers);
            res.status=200;
            if(playerConnected==serverConfig->maxPlayers)
            {
                if(!gameStarted )
                {
                    if(!players[id]->ready)
                        res.set_header("order","ReqReady");
                }
                else
                {
                     if(!gameEnd)
                    {
                        string order="YourTurn";
                        if(id!=turn)
                        {
                            order="WaitTurn";
                            res.set_header("NameWait",players[turn]->name);
                            res.set_header("IdWait",to_string(turn));
                        }
                        res.set_header("order",order);
                    }
                    else
                    {
                        string order="YouWin";
                        if(id!=gameEnd-1){
                            order="OtherWin";
                            res.set_header("NameWin",players[gameEnd-1]->name);
                            res.set_header("IdWin",to_string(gameEnd-1));
                        }
                        res.set_header("order",order);
                    }
                    res.set_header("map",mapGame->ConvertMatrixToString());
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
    svr->Get(api,[&](const Request& req, Response& res) {
        try
        {
            int id=GetHeaderId(req,serverConfig->maxPlayers);
            res.status=200;
            if(!gameStarted && playerConnected==serverConfig->maxPlayers)
            {
                if(!players[id]->ready)
                {
                    players[id]->ready=1;
                    playerReady++;
                    consoleWork->SayPlayerReady(id);
                    if(playerReady==playerConnected)
                    {
                        gameStarted=true;
                        srand (time(NULL));
                        turn=rand()%playerConnected;
                    }
                    else 
                        res.set_header("message","Wait for other players");
                }
            }
        }
        catch(const std::exception& e)
        {
            res.status=500;
        }
    });
}
void HttpServerCorridor::InitTurnApi(string api)
{
    svr->Get(api,[&](const Request& req, Response& res) {
        try
        {
            int id=GetHeaderId(req,serverConfig->maxPlayers);
            res.status=200;
            if(gameEnd)
                res.status=503;
            else if(gameStarted)
            {
                if(turn!=id)
                    res.status=501;
                else 
                {
                    string order=GetValHeader(req,"order");
                    if(order=="wall")
                    {
                        pair<int,int> pos={GetValIntHeader(req,"x"),GetValIntHeader(req,"y")};
                        int dir=GetValIntHeader(req,"dir");
                        if(mapGame->CreateWall(pos,dir))
                            GoNextTurn(turn,serverConfig->maxPlayers);
                        else
                            res.status=502; //you cant do this
                    }
                    else if(order=="move")
                    {
                        int dir=GetValIntHeader(req,"dir");
                        if(mapGame->MovePlayer(players[id]->pos,dir))
                        {
                            if(mapGame->CheckPlayerWin(players[id]->pos))
                            {
                                gameEnd=id+1;
                                consoleWork->SayGameEnd(players[id]->name,id);
                            }
                            else
                                GoNextTurn(turn,serverConfig->maxPlayers);
                        }
                        else
                            res.status=502; //you cant do this
                    } 
                    else res.status=404;
                }
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
    if(players){
        for(int i=0;i<serverConfig->maxPlayers;i++)
        {
            if(players[i]) delete players[i];
        }
        delete [] players;
    }
    if(serverConfig) delete serverConfig;
    if(consoleWork) delete consoleWork;
    if(mapGame) delete mapGame;
    delete svr;
}