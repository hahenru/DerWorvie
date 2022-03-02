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
WriteLog::~WriteLog(){
    this->output_stream.close();
}

WriteLog::WriteLog(){
    std::string file = ".\\error.log";
    this->fileName = file;
    if(!output_stream.is_open()){
        this->output_stream.open(this->fileName,std::ios::app|std::ios::out|std::ios::in);
    }
#ifdef hahenru_was_as_akashashi
    this->setLogLevel(255);
#else
    this->setLogLevel(debug|info);
#endif
}

WriteLog& WriteLog::getNewLogger(){
    static WriteLog itWillBeJustOne;
    return itWillBeJustOne;
}

void WriteLog::init(std::string file,char LV){
    this->fileName = file;
    if(!output_stream.is_open()){
        this->output_stream.open(this->fileName,std::ios::app|std::ios::out|std::ios::in);
    }
#ifdef hahenru_was_as_akashashi
    this->setLogLevel(255);
#else
    this->setLogLevel(LV);
#endif
}

void WriteLog::log(std::string why,unsigned char LV){
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
    }
}
	
void WriteLog::setLogLevel(unsigned char LV){
    this->logLV = LV;
}

/*
本條當初用PS製作的簽到表，上面的表格一成不變
我總是不知道為什麼明明口頭表明需要的東西就好了
卻還要明確的寫出來。
*/
char WriteLog::logLV;
std::string WriteLog::fileName;
std::ofstream WriteLog::output_stream;

}

