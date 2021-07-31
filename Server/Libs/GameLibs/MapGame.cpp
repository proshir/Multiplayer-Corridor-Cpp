#include "MapGame.h"

using namespace std;

MapGame::MapGame(pair <int,int> _size):height(_size.first),width(_size.second)
{
    matrix=new int* [height];
    for(int i=0;i<height;i++)
    {
        matrix[i]=new int[width];
        for(int j=0;j<width;j++)
            matrix[i][j]=0;
    }
}
void MapGame::SetPlayerPos(pair <int,int> &pos,int id)
{
    srand (time(NULL));
    do
    {
        int z=rand()%4;
        switch(z)
        {
            case 0:
                pos={0,0};
                break;
            case 1:
                pos={0,width-1};
                break;
            case 2:
                pos={height-1,width-1};
                break;
            case 3:
                pos={height-1,0};
        }
    } while (matrix[pos.first][pos.second]);   
    matrix[pos.first][pos.second]=id+1;
}
bool MapGame::MovePlayer(pair <int,int> &pos,int dir)
{ //mistake we have to fix this
    int color=matrix[pos.first][pos.second];
    pair<int,int> ans={pos.first,pos.second};
    switch(dir)
    {
        case 0: //Right
            ans.second++;
            break;
        case 1: //Down
            ans.first++;
            break;
        case 2: //Left
            ans.second--;
            break;
        case 3: //Up
            ans.first--;
            break;
        default:
            throw exception();
    }
    if(ans.first<height && ans.first>=0 && ans.second<width &&ans.second>=0)
        if(matrix[ans.first][ans.second]==0)
        {
            matrix[pos.first][pos.second]=0;
            matrix[ans.first][ans.second]=color;
            pos=ans;
            return 1;
        }
    return 0;
}
bool MapGame::CreateWall(pair <int,int> pos,int dir)
{
    if(matrix[pos.first][pos.second]) return 0;
    switch(dir)
    {
        case 0: // Left to right
            if(pos.second+1<width && pos.second>=1)
                if(!matrix[pos.first][pos.second+1] && !matrix[pos.first][pos.second-1])
                {
                    matrix[pos.first][pos.second+1]=5;
                    matrix[pos.first][pos.second]=5;
                    matrix[pos.first][pos.second-1]=5;
                    return 1;
                }
            break;
        case 1:
            if(pos.first+1<height && pos.first>=1)
                if(!matrix[pos.first+1][pos.second] && !matrix[pos.first-1][pos.second])
                {
                    matrix[pos.first+1][pos.second]=5;
                    matrix[pos.first][pos.second]=5;
                    matrix[pos.first-1][pos.second]=5;
                    return 1;
                }
            break;
        default:
            throw exception();
    }
    return 0;
}
bool MapGame::CheckPlayerWin(pair <int,int> pos)
{
    return pos.first==(height/2) && pos.second==(width/2);
}
string MapGame::ConvertMatrixToString()
{
    string ans=to_string(height)+"|"+to_string(width)+"|";
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
        {
            ans+=matrix[i][j]==5 ? '#' : (matrix[i][j]+'0');
        }
    return ans;
}
MapGame::~MapGame()
{
    for(int i=0;i<height;i++)
        delete matrix[i];
    delete [] matrix;
}
