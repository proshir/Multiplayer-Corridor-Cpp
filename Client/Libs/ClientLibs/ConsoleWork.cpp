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
    cout<<"You join this server With id = "+to_string(id)<<endl;
}
void ConsoleWork::SayGoodbye()
{
    cout<<"Goodbye\n...Enjoy Your Life...\n";
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
bool ConsoleWork::PrintMap(string map)
{
    if(map!=lastMap)
    {
        GameMap *gameMap=new GameMap(map);
        cout<<"\n   |";
        for(int j=0;j<gameMap->width;j++)
        {
            cout<<j<<" ";
        }
        cout<<'\n';
        for(int i=0;i<(gameMap->height);i++)
        {
            cout<<i<<" ";
            if(i<10) cout<<" ";
            cout<<"|";
            for(int j=0;j<(gameMap->width);j++)
                cout<<gameMap->fullMap[i][j]<<" ";
            cout<<'\n';
        }
        lastMap=map;
        delete gameMap;
        return true;
    }
    return false;
}
void ConsoleWork::SayYourTurn(bool& flag,int& x,int& y,int& dir)
{
    do
    {
        string sFlag,sDir;
        cout<<"-------------------------\n";
        cout<<"0.You want move your self!\n";
        cout<<"1.You want put a Wall\n";
        cout<<"-------------------------\n";
        cin>>sFlag;
        if(sFlag=="0") 
        {
            flag=false;
            cout<<"-------------------------\n";
            cout<<"You want go \n";
            cout<<"0.Right   1.Down    2.Left    3.Up\n";
            cout<<"-------------------------\n";
            cin>>dir;
            if(dir>=4 || dir<0)
                continue;
            break;
        }
        else if(sFlag=="1") 
        {
            cout<<"-------------------------\n";
            cout<<"Say X pos (0base)\n";
            cout<<"-------------------------\n";
            cin>>x;
            cout<<"-------------------------\n";
            cout<<"Say Y pos (0base)\n";
            cout<<"-------------------------\n";
            cin>>y;
            cout<<"-------------------------\n";
            cout<<"You want go \n";
            cout<<"0.Right-Left   1.Up-Down\n";
            cout<<"-------------------------\n";
            cin>>dir;
            if(dir>=2 || dir<0)
                continue;
            flag=true;
            break;
        }
        else continue;
    } while (true);
}
void ConsoleWork::SayYouCantDoThis()
{
    cout<<"You Can't Do This\n";
}