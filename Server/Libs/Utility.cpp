#include <iostream>
#include "ServerLibs/httplib.h"
using namespace httplib;
using namespace std;
int ConvertStringToInt(string s)
{
    int tmp=0;
    for(int i=0;i<s.length();i++)
    {
        tmp=tmp*10 + (s[i]-'0');
        if(s[i]>'9' || s[i]<'0') throw exception();
    }
    return tmp;
}
string GetValHeader(Request req,string header)
{
    if(req.has_header(header.data()))
        return req.get_header_value(header.data());
    throw exception();
}
int GetValIntHeader(Request req,string header)
{
    return ConvertStringToInt(GetValHeader(req,header));
}
int GetHeaderId(Request req,int maxPlayers)
{
    int ans=GetValIntHeader(req,"id");
        if(ans<maxPlayers && ans>=0) return ans;
    throw exception();
}
void GoNextTurn(int& turn,int maxPlayers)
{
    turn=(turn+1)%maxPlayers;
}