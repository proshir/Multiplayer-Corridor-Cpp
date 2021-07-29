#include "ConsoleWork.h"

using namespace std;

void ConsoleWork::GetServerConfig(ServerConfig *serverConfig)
{
    string serverName;
    int port;
    int maxPlayers;
    cout<<"Please Enter Your Server Name\n";
    getline(cin,serverName);
    cout<<"Please Enter Port\n";
    cin>>port;
    do
    {
        cout<<"Please Enter MaxPlayers (2-4)\n";
        cin>>maxPlayers; 
    } while (maxPlayers>4 && maxPlayers<2);
    ServerConfig *other=new ServerConfig(serverName,port,maxPlayers);
    serverConfig=other;
}