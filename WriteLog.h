#ifndef __WRITE_LOG_CLASS__
#define __WRITE_LOG_CLASS__

#include <iostream>
#include <fstream>
#include <string>
	
namespace Kashashi{
	
/*
簽到表，或許只是一張單純的紙，他總是說這張紙很特別，無法被取代
這張紙從這個組織，組成以來就已經存在
本條總是想盡辦法回收再利用，或許是為了省錢吧?
*/
class writeLog_I{
public:
    writeLog_I(writeLog_I const& obj) = delete;
    static const unsigned char none = 0; //0x00000000
    static const unsigned char debug= 1; //0x00000001
    static const unsigned char info = 2; //0x00000010
    static const unsigned char warn = 4; //0x00000100
    static const unsigned char error =8; //0x00001000
    static const unsigned char criti=16; //0x00010000
    static const unsigned char fatal=32; //0x00100000
    static const unsigned char def1 =64; //0x01000000
    static const unsigned char def2=128; //0x10000000

    void init(std::string file,char LV);
    void log(std::string why,unsigned char LV);
    static writeLog_I& getNewLogger();
    virtual ~writeLog_I();
    void setLogLevel(unsigned char LV);
protected:
private:   
    writeLog_I();
    static char logLV;
    static std::string fileName;
    static std::ofstream output_stream;
};

}
#endif//__WRITE_LOG_CLASS__
