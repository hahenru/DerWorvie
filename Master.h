#ifndef MASTER_GOD_OF_KNOW_ANYTHING_CLASS
#define MASTER_GOD_OF_KNOW_ANYTHING_CLASS

#include "WriteLog.h"
#include "windowHandler.h"

namespace Kashashi{

class master{
private:
    writeLog_I& loger = writeLog_I::getNewLogger();
    windowHandle window;
public:
    void argvProcess(int argc, const char** const argv);
    master();
};

}
#endif//MASTER_GOD_OF_KNOW_ANYTHING_CLASS
