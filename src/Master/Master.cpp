#include "Master.h"
#include "..\Manager\windowManager\windowManager.h"

namespace Kashashi{

Master::Master(){}

void Master::argvProcess(int argc, char** argv){
    if(argc!=1){
        for(int i=0; i<argc; i++){
        }
    }
}

void Master::updateWindow(){
    primeWindow.updateScreen();
}
void Master::updateWindowEvent(){
    primeWindow.updateScreen();
}
bool Master::needShutdown(){
    return primeWindow.windowShouldBeClose();
}

}
