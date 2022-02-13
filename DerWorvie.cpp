#include <iostream>
#include <string>
#include <Windows.h>
#include "WriteLog.h"
#include "Master.h"

Kashashi::writeLog_I& sign_in_form = Kashashi::writeLog_I::getNewLogger();

/*
東西掛好，旁邊有衣架，故事很快就開始
那個宗澤，麻煩你幫我把簽到表拿出來放著
筆順便。
*/
__attribute__((constructor)) void init(){
    Kashashi::writeLog_I::getNewLogger().init(".\\.log",Kashashi::writeLog_I::debug|Kashashi::writeLog_I::info);
    std::string forFirstLogTest = "初始化完成";
    Kashashi::writeLog_I::getNewLogger().log(forFirstLogTest, Kashashi::writeLog_I::info);
}
/*
離開的時候要記得你放置的物品，別忘了簽到
*/
__attribute__((destructor)) void terminate(){
    std::string forLastLogTest = "我該怎麼逃離這鬼地方?";
    Kashashi::writeLog_I::getNewLogger().log(forLastLogTest, Kashashi::writeLog_I::info);
}

/*
你知道嗎?
這就是一切的開端
就從這邊來的
姑且就稱呼他叫做 曾羽敖 好了
距離今天2022/2/11過去了五年了
*/
signed main(int argc, char** argv){

}
