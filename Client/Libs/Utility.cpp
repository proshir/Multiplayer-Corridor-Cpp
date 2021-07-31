#include <iostream>
#include "ClientLibs/httplib.h"
using namespace httplib;
using namespace std;
int ConvertStringToInt(string s)
{
    int tmp=0;
    for(int i=0;i<s.length();i++)
    {
        tmp=tmp*10 + (s[i]-'0');
        if(s[i]>'9' || s[i]<'0') throw  exception();
    }
    return tmp;
}
string GetValHeader(Result& res,string header)
{
    if(res.value().has_header(header.data()))
        return res.value().get_header_value(header.data());
    throw exception();
}
int GetValIntHeader(Result& res,string header)
{
    return ConvertStringToInt(GetValHeader(res,header));
}
void WaitTurn(Result& res,ConsoleWork* consoleWork)
{
    string name=GetValHeader(res,"NameWait");
    int id=GetValIntHeader(res,"IdWait");
    consoleWork->SayWaitPlayer(name,id);
}
void WinHelper(Result& res,ConsoleWork* consoleWork)
{
    string name=GetValHeader(res,"NameWin");
    int id=GetValIntHeader(res,"IdWin");
    consoleWork->SayWin(name,id);
}