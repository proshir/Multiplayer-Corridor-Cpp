#include "Libs/HttpClientCorridor.cpp"
int main()
{
    HttpClientCorridor *httpClientCorridor=new HttpClientCorridor();
    httpClientCorridor->InitConnectConfigFromConsole();
    httpClientCorridor->InitClient();
    if(!httpClientCorridor->JoinToServer("/connect")) return 0;
}