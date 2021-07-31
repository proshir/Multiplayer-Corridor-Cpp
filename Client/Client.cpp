#include "Libs/HttpClientCorridor.cpp"
int main()
{
    HttpClientCorridor *httpClientCorridor=new HttpClientCorridor("/connect","/status","/ready","/turn");
    httpClientCorridor->InitConnectConfigFromConsole();
    httpClientCorridor->InitClient();
    if(!httpClientCorridor->JoinToServer()) return 0;
    httpClientCorridor->InitStatus();
}