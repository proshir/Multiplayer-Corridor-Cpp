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
        if(s[i]>'9' || s[i]<'0') throw new exception();
    }
    return tmp;
}
int GetHeaderId(Request req,int maxPlayers)
{
    int ans;
    if(req.has_header("id"))
    {
        ans= ConvertStringToInt(req.get_header_value("id"));
        if(ans<maxPlayers) return ans;
    }
    throw new exception();
}