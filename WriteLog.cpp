#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "WriteLog.h"
	
namespace Kashashi{
	
/*
總有人說著總哪裡來就從哪裡回去
或許有天我可以把它種進土裡面?
*/
writeLog_I::~writeLog_I(){
    this->output_stream.close();
}

writeLog_I::writeLog_I(){
    std::string file = ".\\log";
    this->fileName = file;
    if(!output_stream.is_open()){
        this->output_stream.open(this->fileName,std::ios::app|std::ios::out|std::ios::in);
    }
    this->setLogLevel(debug|info);
}

writeLog_I& writeLog_I::getNewLogger(){
    static writeLog_I itWillBeJustOne;
    return itWillBeJustOne;
}

void writeLog_I::init(std::string file,char LV){
    this->fileName = file;
    if(!output_stream.is_open()){
        this->output_stream.open(this->fileName,std::ios::app|std::ios::out|std::ios::in);
    }
    this->setLogLevel(LV);
}

void writeLog_I::log(std::string why,unsigned char LV){
    if(!output_stream.is_open()){
        std::cout << "error" << "\n";
    }
    if((this->logLV&LV)==LV){
        std::string Now_level;
        switch(LV){
            case(this->debug):
                Now_level = "debug|";
                break;
            case(this->info):
                Now_level = "info|";
                break;
            case(this->warn):
                Now_level = "warn|";
                break;
            case(this->error):
                Now_level = "error|";
                break;
            case(this->criti):
                Now_level = "criti|";
                break;
            case(this->fatal):
                Now_level = "fatal|";
                break;
            default:
                Now_level = "不明記錄等級(未授權的紀錄)|";
                break;
        }
        this->output_stream << std::hex <<Now_level << why << "\n";
        this->output_stream.flush();
        std::cout << Now_level << why << "\n";
    }
}
	
void writeLog_I::setLogLevel(unsigned char LV){
    this->logLV = LV;
}

/*
本條當初用PS製作的簽到表，上面的表格一成不變
我總是不知道為什麼明明口頭表明需要的東西就好了
卻還要明確的寫出來。
*/
char writeLog_I::logLV;// = writeLog_I::debug;
std::string writeLog_I::fileName;// = ".\\log";
std::ofstream writeLog_I::output_stream;

}

