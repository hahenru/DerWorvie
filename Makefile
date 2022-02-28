CXX = g++
CC = gcc
code = -m64 -fexec-charset=utf-8 -fwide-exec-charset=utf-8 -std=c++2a
subtag = -Wl,-subsystem,windows
gladdir = include\GLAD
glfwdir = include\GLFW
SRC = src
OBJ = obj
BIN = bin

.PHONY: DerWorvie.exe
DerWorvie.exe: Master.o windowManager.o
	$(CXX) $(code) -g -I$(glfwdir) -L$(gladdir) -Llib -DGLFW_DLL -o $(BIN)\DerWorvie.exe $(SRC)\DerWorvie.cpp $(OBJ)\Master.o $(OBJ)\windowManager.o  -lglad -lglfw3 -limm32

.PHONY: Master.o
Master.o: 
	$(CXX) $(code) -g -c $(SRC)\Master\Master.cpp -o $(OBJ)\Master.o

.PHONY: windowManager.o
windowManager.o:
	$(CXX) $(code) -g -c $(SRC)\Manager\windowManager\windowManager.cpp -o $(OBJ)\windowManager.o

.PHONY: WriteLog.o
WriteLog.o:
	$(CXX) $(code) -g -c $(SRC)\WriteLog\WriteLog.cpp
