#include "HttpClientCorridor.h"

using namespace std;

HttpClientCorridor::HttpClientCorridor()
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
bool HttpClientCorridor::JoinToServer(string api)
{
    bool tryJoin;
    Headers headers={
        {"name",connectConfig->name}
    };
    do
    {      
        try{  
            if(auto res=client->Get(api.data(),headers))
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
                else throw new exception();
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
bool HttpClientCorridor::InitStatusCore(string api,string apiReady)
{
   try
   {
       if(auto res=client->Get(api.data()))
       {
           if(res->status==200)
           {
               string order=GetValHeader(res,"order");
               if(order=="ReqReady")
               {
                   if(consoleWork->AskYouReady())
                        SendReady(apiReady);
               }
           }
           else throw new exception();
       }
   }
   catch(const std::exception& e)
   {

   }
    
}
void HttpClientCorridor::SendReady(string api)
{
    try
   {
       auto res=client->Get(api.data());
   }
   catch(const std::exception& e)
   {

   }
}