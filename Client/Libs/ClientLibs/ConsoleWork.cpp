#include "ConsoleWork.h"
using namespace std;
void ConsoleWork::GetConnectConfig(ConnectConfig *&connectConfig)
{
    string name,address;
    int port;
    cout<<"Please Enter Your Name\n";
    getline(cin,name);
    cout<<"Please Enter Address\n";
    cin>>address;
    cout<<"Please Enter Port\n";
    cin>>port;
    connectConfig = new ConnectConfig(name,address,port);
}
void ConsoleWork::SayServerFull()
{
    cout<<"This Server Is Full\n";
}
bool ConsoleWork::WantToTry()
{
    string ans;
    cout<<"If You Want To Try Again, Please Say \"Yes\"\n";
    cin>>ans;
    return ans=="Yes";
}
void ConsoleWork::SayYouJoin(int id)
{
    cout<<"You join this server With id = "+id<<endl;
}
void ConsoleWork::SayGoodbye()
{
    cout<<"Goodbye\n...Enjoy Your Life...";
}
bool ConsoleWork::AskYouReady()
{
    string ans;
    cout<<"Are You Ready?, Please Say \"Yes\"\n";
    cin>>ans;
    return ans=="Yes";
}
void ConsoleWork::SayWaitPlayer(string name,int id)
{
    cout<<"Wait For "+name+" With id= "+to_string(id)<<endl;
}
void ConsoleWork::SayWin(string name,int id)
{
    if(id==-1) 
        cout<<"You Win\n";
    else 
        cout<<name+" with Id= "+to_string(id)+" Win this Game!\n";
}
void ConsoleWork::PrintMap(string map)
{
    if(map!=lastMap)
    {
        GameMap gameMap(map);
        for(int i=0;i<gameMap.height;i++)
        {
            for(int j=0;j<gameMap.width;j++)
                cout<<gameMap.fullMap[i][j]<<" ";
            cout<<'\n';
        }
    }
}