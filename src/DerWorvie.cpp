#include <iostream>
#include <string>
#include <Windows.h>
#include "Master\Master.h"

/*
東西掛好，旁邊有衣架，故事很快就開始
那個宗澤，麻煩你幫我把簽到表拿出來放著
筆順便。
*/
__attribute__((constructor)) void init(){
}
/*
離開的時候要記得你放置的物品，別忘了簽到
*/
__attribute__((destructor)) void terminate(){
}

/*
你知道嗎?
這就是一切的開端
就從這邊來的
姑且就稱呼他叫做 曾羽敖 好了
距離今天2022/2/11過去了五年了
*/
signed main(int argc, char** argv){
    Kashashi::Master GameMasterProcess;
    GameMasterProcess.argvProcess(argc,argv);
    while(GameMasterProcess.update()){}
    return 0;
    
FATALHANDLE:
    return 0;
}
