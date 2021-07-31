#include "GameMap.h"

GameMap::GameMap(string s)
{
    int o=0,d;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='|') 
        {
            o++;
            if(o==2)
            {
                d=i+1;
                fullMap=new string[height];
            }
            continue;
        }
        switch (o)
        {
            case 0:
                height=height*10 +(s[i]-'0');
                break;
            case 1:
                width=width*10 +(s[i]-'0');
                break;
            case 2:
                fullMap[(i-d)/width][(i-d)%width]=s[i];
        }
    }
}

GameMap::~GameMap()
{
    delete fullMap;
}