#ifndef __MAP_GAME_H_I344GZEC12CS__
#define __MAP_GAME_H_I344GZEC12CS__

///////////////////////////////////////////////////////////
/// @brief MapGame
///
#include<iostream>
using namespace std;
class MapGame
{
public:
    MapGame(pair<int,int> _size);
    bool MovePlayer(pair<int,int> &,int);
    bool CreateWall(pair<int,int>,int dir);
    bool CheckPlayerWin(pair<int,int>);
    void SetPlayerPos(pair<int,int> &,int);
    string ConvertMatrixToString();
    ~MapGame();
private:
    const int width;
    const int height;
    int** matrix;
};
#endif  // __MAP_GAME_H_I344GZEC12CS__
