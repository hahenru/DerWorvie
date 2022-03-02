#include "Master.h"
#include "..\Manager\windowManager\windowManager.h"
#include "..\WriteLog\WriteLog.h"

namespace Kashashi{

Master::Master(){
    primeWindow.windowInit();
    primeWindow.glfwSetting();
}

void Master::argvProcess(int argc, char** argv){
    if(argc!=1){
        for(int i=0; i<argc; i++){
        }
    }
}

bool Master::update(){
    primeWindow.event();
    primeWindow.processInput();
    glClearColor(0,1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    primeWindow.updateScreen();
    if(!primeWindow.windowShouldBeClose()){
        return true;
    }
    return false;
}

}
