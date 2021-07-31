#ifndef __GAME_MAP_H_9VP9A0TUKLUA__
#define __GAME_MAP_H_9VP9A0TUKLUA__

///////////////////////////////////////////////////////////
/// @brief GameMap
///
#include <iostream>
using namespace std;
class ConsoleWork;
class GameMap
{
    friend class ConsoleWork;
public:
    GameMap(string);
    ~GameMap();
private:
    string *fullMap;
    int width;
    int height;
};

#endif  // __GAME_MAP_H_9VP9A0TUKLUA__
