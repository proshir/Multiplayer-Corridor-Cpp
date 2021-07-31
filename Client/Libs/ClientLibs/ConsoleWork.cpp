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