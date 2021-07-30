#include "Libs/HttpServerCorridor.cpp"
int main()
{
    HttpServerCorridor *httpServerCorridor=new HttpServerCorridor();
    httpServerCorridor->InitServerConfigFromConsole();
    httpServerCorridor->InitPlayers();
    httpServerCorridor->InitConnectApi("/connect");
    httpServerCorridor->InitStatusApi("/status");
    httpServerCorridor->InitReadyApi("/ready");
    httpServerCorridor->StartListen();
}
