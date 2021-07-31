#ifndef __CONSOLE_WORK_H_R51JU7C4KP2C__
#define __CONSOLE_WORK_H_R51JU7C4KP2C__

///////////////////////////////////////////////////////////
/// @brief ConsoleWork
///
#include "ServerConfig.h"
class ConsoleWork
{
public:
    void GetServerConfig(ServerConfig *&);
    void SayServerRun();
    void SayPlayerEntered(string name,int id);
    void SayPlayerReady(int id);
    void SayGameEnd(string name,int id);
};

#endif  // __CONSOLE_WORK_H_R51JU7C4KP2C__
