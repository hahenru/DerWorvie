#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER

#include <windows.h>
#include "..\..\..\include\GLAD\glad.h"
#include "..\..\..\include\GLFW\glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "..\..\..\include\GLFW\glfw3native.h"
#include "..\..\WriteLog\WriteLog.h"
#include <GL\gl.h>
#include <string>

namespace Kashashi{
    
class WindowManager{
private:
    GLFWwindow* window;
    GLFWmonitor* primeMonitor;
    bool fullScreenFlag = true;
    void* loggerCallback;
    static short glfwInitCount;
public:
    WindowManager();
    ~WindowManager();
    void setFullScreen(bool needFull);
    void updateScreen();
    void event();
    bool windowShouldBeClose();
    void windowInit();
    void glfwSetting();
    void processInput();
};

}
#endif//WINDOW_MANAGER
