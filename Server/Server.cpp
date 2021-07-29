#include<iostream>
#include "httplib.h"
#include "ServerLibs/ServerConfig.h"
#include "ServerLibs/ConsoleWork.h"
using namespace std;
using namespace httplib;
int main()
{
    ServerConfig *serverConfig=new ServerConfig();
    ConsoleWork *consoleWork=new ConsoleWork();
    consoleWork->GetServerConfig(serverConfig);
    
}
