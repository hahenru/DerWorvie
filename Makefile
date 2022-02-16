CXX = g++
CC = gcc
code = -m64 -fexec-charset=utf-8 -fwide-exec-charset=utf-8 -std=c++2a
hwaak = -Dhahenru_was_as_akashashi

.PHONY: DerWorvie.exe
DerWorvie.exe: WriteLog.o
	$(CXX) $(code) -g -o DerWorvie.exe DerWorvie.cpp WriteLog.o

.PHONY: WriteLog.o
WriteLog.o:
	$(CXX) $(code) -g -c WriteLog.cpp $(hwaak)
