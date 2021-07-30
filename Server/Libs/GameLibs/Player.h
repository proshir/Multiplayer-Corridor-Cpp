#ifndef __PLAYER_H_0Q3OY350M0YQ__
#define __PLAYER_H_0Q3OY350M0YQ__

///////////////////////////////////////////////////////////
/// @brief Player
///
#include <iostream>
using namespace std;
class HttpServerCorridor;
class Player
{
    friend class HttpServerCorridor;
public:
    Player(string _name,int _id):name(_name),id(_id),ready(0){}
private:
    const int id;
    const string name;
    bool ready;
    pair<int,int> pos;
};

#endif  // __PLAYER_H_0Q3OY350M0YQ__
