#include "windowHandler.h"
#include "WriteLog.h"
#include "GLFW\glfw3.h"
#include "GLFW\glfw3native.h"
#include "GLAD\glad.h"
#include <GL/gl.h>
#include <string>



namespace Kashashi{
    
extern writeLog_I& sign_in_form;

windowHandle::windowHandle(){
    if (!glfwInit()){
    // Initialization failed
    }
    glfwSetErrorCallback(error_callback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if(!window){
        //張大你的眼睛，你啥都沒看到對吧?
        //這他媽就是問題所在
        sign_in_form.log("是你的視窗呢?",writeLog_I::error);
    }
}

windowHandle::~windowHandle(){
    glfwTerminate();
}

void windowHandle::error_callback(int error, const char* description){
    sign_in_form.log(std::to_string(error),writeLog_I::error);
    sign_in_form.log(description, writeLog_I::error);
}


}
