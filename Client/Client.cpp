#include "Libs/HttpClientCorridor.cpp"
int main()
{
    HttpClientCorridor *httpClientCorridor=new HttpClientCorridor();
    httpClientCorridor->InitConnectConfigFromConsole();
}