CXX = g++
CC = gcc
code = -m64 -fexec-charset=utf-8 -fwide-exec-charset=utf-8 -std=c++2a
subtag = -Wl,-subsystem,windows
gladdir = include\GLAD
glfwdir = include\GLFW
SRC = src
OBJ = obj
BIN = bin

FINALSTEP = $(SRC)\DerWorvie.cpp

.PHONY: DerWorvie.exe
DerWorvie.exe: Master.o windowManager.o WriteLog.o
	$(CXX) $(code) -g -I$(glfwdir) -L$(gladdir) -Llib -DGLFW_DLL -o $(BIN)\DerWorvie.exe $(FINALSTEP) -lglad -lglfw3 -limm32

.PHONY: Master.o
Master.o: 
	$(CXX) $(code) -g -c $(SRC)\Master\Master.cpp -o $(OBJ)\Master.o

FINALSTEP += $(OBJ)\Master.o

.PHONY: windowManager.o
windowManager.o:
	$(CXX) $(code) -g -c $(SRC)\Manager\windowManager\windowManager.cpp -o $(OBJ)\windowManager.o

FINALSTEP += $(OBJ)\windowManager.o


#這個必須最後
.PHONY: WriteLog.o
WriteLog.o:
	$(CXX) $(code) -g -c $(SRC)\WriteLog\WriteLog.cpp -o $(OBJ)\WriteLog.o

FINALSTEP += $(OBJ)\WriteLog.o
