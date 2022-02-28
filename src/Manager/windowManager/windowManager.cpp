#include "windowManager.h"
#include "..\..\..\include\GLAD\glad.h"
#include "..\..\..\include\GLFW\glfw3.h"
#include "..\..\..\include\GLFW\glfw3native.h"
#include <GL\gl.h>
#include <string>
#include <stdio.h>


namespace Kashashi{

WindowManager::WindowManager(){
    if (!glfwInit()){
    //初始化失敗
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    primeMonitor = glfwGetPrimaryMonitor();
    window = glfwCreateWindow(600, 800, "測試中", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    if(window == nullptr){
        //張大你的眼睛，你啥都沒看到對吧?
        //這他媽就是問題所在
    }
    //setFullScreen(true);
}

WindowManager::~WindowManager(){
    glfwTerminate();
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


}
