#ifndef __CONSOLE_WORK_H_R1HX2IKL2P2W__
#define __CONSOLE_WORK_H_R1HX2IKL2P2W__

///////////////////////////////////////////////////////////
/// @brief ConsoleWork
///
#include "ConnectConfig.h"
#include "GameMap.h"
class ConsoleWork
{
public:
    ConsoleWork():lastMap(""){}
    void GetConnectConfig(ConnectConfig *&);
    void SayServerFull();
    bool WantToTry();
    void SayYouJoin(int id);
    void SayGoodbye();
    bool AskYouReady();
    void SayWaitPlayer(string,int);
    void SayWin(string="",int=-1);
    bool PrintMap(string map);
    void SayYourTurn(bool&,int&,int&,int&);
    void SayYouCantDoThis();
private :
    string lastMap;
};

#endif  // __CONSOLE_WORK_H_R1HX2IKL2P2W__
