#ifndef MASTER_GOD_OF_KNOW_ANYTHING_CLASS
#define MASTER_GOD_OF_KNOW_ANYTHING_CLASS

#include "..\Manager\windowManager\windowManager.h"

namespace Kashashi{

class Master{
private:
    WindowManager primeWindow;
public:
    Master();
    void argvProcess(int argc, char** argv);
    bool update();

};

}
#endif//MASTER_GOD_OF_KNOW_ANYTHING_CLASS
