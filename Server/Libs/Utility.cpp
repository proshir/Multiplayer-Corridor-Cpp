#include <iostream>
#include "ServerLibs/httplib.h"
using namespace httplib;
using namespace std;
int ConvertStringToInt(string s)
{
    int tmp=0;
    for(int i=0;i<s.length();i++)
        tmp=tmp*10 + (s[i]-'0');
    return tmp;
}
int GetHeaderId(Request req)
{
    if(req.has_header("id"))
        return ConvertStringToInt(req.get_header_value("id"));
    else throw new exception();
}