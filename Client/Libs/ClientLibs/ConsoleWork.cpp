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