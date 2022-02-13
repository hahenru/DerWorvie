#include <iostream>
#include <string>
#include <fstream>
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
    std::string dir = ".\\";
    std::string file = "log";
    writeLog_I(dir,file);
}

writeLog_I::writeLog_I(const std::string dir, const std::string file){
    std::string output_file_name = dir + file;
    this->fileName = output_file_name;
    this->output_stream.open(output_file_name);
    this->setLogLevel(debug|info);
}

writeLog_I* writeLog_I::getNewLogger(){
    if(writeLog_selfptr==NULL){
        writeLog_selfptr = new writeLog_I();
    }
    return writeLog_selfptr;
}

void writeLog_I::log(std::string why,unsigned char LV){
    if((this->logLV^LV)==0){
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
        this->output_stream << Now_level << why << "\n";
    }
}

void writeLog_I::setLogLevel(unsigned char LV){
    this->logLV = LV;
}

}