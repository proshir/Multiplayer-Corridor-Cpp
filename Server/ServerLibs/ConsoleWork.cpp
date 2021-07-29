#include "ConsoleWork.h"

using namespace std;

void ConsoleWork::GetServerConfig(ServerConfig *& serverConfig)
{
    string serverName;
    string address;
    int port;
    int maxPlayers;
    cout<<"Please Enter Server Name\n";
    getline(cin,serverName);
    cout<<"Please Enter Address\n";
    cin>>address;
    cout<<"Please Enter Port\n";
    cin>>port;
    do
    {
        cout<<"Please Enter MaxPlayers (2-4)\n";
        cin>>maxPlayers; 
    } while (maxPlayers>4 && maxPlayers<2);
    serverConfig=new ServerConfig(serverName,address,port,maxPlayers);
}