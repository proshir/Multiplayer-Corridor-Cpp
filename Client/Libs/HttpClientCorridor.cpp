#include "HttpClientCorridor.h"

using namespace std;

HttpClientCorridor::HttpClientCorridor()
{
    consoleWork=new ConsoleWork();
    connectConfig=0;
}
void HttpClientCorridor::InitConnectConfigFromConsole()
{
    consoleWork->GetConnectConfig(connectConfig);
}