#include "HttpClientCorridor.h"

using namespace std;

HttpClientCorridor::HttpClientCorridor(string _apiConnect,string _apiStatus,string _apiReady,string _apiTurn):
    apiConnect(_apiConnect),apiStatus(_apiStatus),apiReady(_apiReady),apiTurn(_apiTurn)
{
    consoleWork=new ConsoleWork();
    connectConfig=0;
    client=0;
}
void HttpClientCorridor::InitConnectConfigFromConsole()
{
    consoleWork->GetConnectConfig(connectConfig);
}
void HttpClientCorridor::InitClient()
{
    client=new Client(connectConfig->address,connectConfig->port);
}
bool HttpClientCorridor::JoinToServer()
{
    bool tryJoin;
    Headers headers={
        {"name",connectConfig->name}
    };
    do
    {      
        try{  
            if(auto res=client->Get(apiConnect.data(),headers))
            {
                if(res->status==200)
                {
                    connectConfig->id=GetValIntHeader(res,"id");
                    client->set_default_headers({{"id",to_string(connectConfig->id)}});
                    consoleWork->SayYouJoin(connectConfig->id);
                    return true;
                }
                else if(res->status==510)
                {
                    consoleWork->SayServerFull();
                }
                else throw exception();
            }
        }
        catch(const std::exception& e)
        {
            cout<<"An Error Happend!\n";
        }
        tryJoin=consoleWork->WantToTry();
    } while (tryJoin);
    consoleWork->SayGoodbye();
    return false;
}
void HttpClientCorridor::InitStatus()
{
    do
    {
        sleep(1);
    } while (!InitStatusCore());
    consoleWork->SayGoodbye();
}
bool HttpClientCorridor::InitStatusCore()
{
   try
   {
       if(auto res=client->Get(apiStatus.data()))
       {
           if(res->status==200)
           {
               string order=GetValHeader(res,"order");
               if(order=="ReqReady")
               {
                   if(consoleWork->AskYouReady())
                        SendReady();
               }
               else
               { 
                    if(consoleWork->PrintMap(GetValHeader(res,"map")) || order=="YourTurn" || order=="YouWin")
                    {
                        if(order=="YourTurn")
                        {
                            GetTurn();
                        }
                        else if(order=="WaitTurn")
                        {
                            WaitTurn(res,consoleWork);
                        }
                        else if(order=="YouWin")
                        {
                            consoleWork->SayWin();
                            return true;
                        }
                        else if(order=="OtherWin")
                        {
                            WinHelper(res,consoleWork);
                            return true;
                        }
                    }
               }
           }
           else throw exception();
       }
   }
   catch(const std::exception& e)
   {

   }
    return false;
}
void HttpClientCorridor::SendReady()
{
    try
   {
       auto res=client->Get(apiReady.data());
   }
   catch(const std::exception& e)
   {

   }
}
void HttpClientCorridor::GetTurn()
{
    try
    {
        bool flag;
        int x,y,dir;
        consoleWork->SayYourTurn(flag,x,y,dir);
        Headers headers={{"dir",to_string(dir)}};
        if(flag)// wall
        {
            headers.emplace("order","wall");
            headers.emplace("x",to_string(x));
            headers.emplace("y",to_string(y));
        } else
        {
            headers.emplace("order","move");
        }
        if(auto res=client->Get(apiTurn.data(),headers))
        {
            if(res->status==502)
            {
                consoleWork->SayYouCantDoThis();
            }
        }
    }
    catch(const std::exception& e)
    {
        
    }
}