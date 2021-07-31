#ifndef __CONSOLE_WORK_H_R1HX2IKL2P2W__
#define __CONSOLE_WORK_H_R1HX2IKL2P2W__

///////////////////////////////////////////////////////////
/// @brief ConsoleWork
///
#include "ConnectConfig.h"
class ConsoleWork
{
public:
    void GetConnectConfig(ConnectConfig *&);
    void SayServerFull();
    bool WantToTry();
    void SayYouJoin(int id);
    void SayGoodbye();
    bool AskYouReady();
};

#endif  // __CONSOLE_WORK_H_R1HX2IKL2P2W__
