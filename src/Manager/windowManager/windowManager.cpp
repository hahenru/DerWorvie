#include "windowManager.h"
#include "..\..\WriteLog\WriteLog.h"
#include "..\..\..\include\GLAD\glad.h"
#include "..\..\..\include\GLFW\glfw3.h"
#include "..\..\..\include\GLFW\glfw3native.h"
#include <GL\gl.h>
#include <string>
#include <stdio.h>


namespace Kashashi{

short WindowManager::glfwInitCount = 0;

WindowManager::WindowManager(){

}

WindowManager::~WindowManager(){
    if(glfwInitCount > 0){
        glfwTerminate();
    }
}
void WindowManager::windowInit(){
    if(glfwInitCount > 0){
        return;
    }
    if(!glfwInit()){
        WriteLog::getNewLogger().log(std::string("glfw初始化錯誤"),WriteLog::error);
    }
    else{
        glfwInitCount++;
    }
}

void WindowManager::glfwSetting(){
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    primeMonitor = glfwGetPrimaryMonitor();
    window = glfwCreateWindow(1920, 1080, "測試中", primeMonitor, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    if(window == nullptr){
        //張大你的眼睛，你啥都沒看到對吧?
        //這他媽就是問題所在
    }
}

void WindowManager::setFullScreen(bool needFull){
    if(fullScreenFlag != needFull){
        fullScreenFlag = needFull;
    }
    if(fullScreenFlag){
        glfwGetVideoMode(primeMonitor);
    }
}
void WindowManager::updateScreen() {
    glfwSwapBuffers(window);
}
void WindowManager::event(){
    glfwPollEvents();
}
bool WindowManager::windowShouldBeClose(){
    return glfwWindowShouldClose(window);
}

void WindowManager::processInput(){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

}
