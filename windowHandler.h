#ifndef WINDOW_HANDLE
#define WINDOW_HANDLE

#include <windows.h>
#include "GLFW\glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW\glfw3native.h"
#include "GLAD\glad.h"
#include <GL/gl.h>

namespace Kashashi{
    
class windowHandle{
private:
    GLFWwindow* window;
public:
    windowHandle();
    ~windowHandle();
    void setLoggerCallback(void* logger);
    static void error_callback(int error, const char* description);
};

}
#endif//WINDOW_HANDLE
