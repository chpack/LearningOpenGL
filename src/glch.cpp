#ifndef GLCH_CPP
#define GLCH_CPP

#include "../include/glch.h"
#include <fstream>

void fb_size_callback(GLFWwindow * window, int width, int height);

Glch::Glch( int width, int height, char * title):vao()
{
    _width = width;
    _height = height;
    _title = title;
    // Init glfw
    glfwInit();
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Create a window
    _window = glfwCreateWindow( _width,_height, _title, nullptr, nullptr);
    if (_window == nullptr)
    {
        std::cout << "failed to create window " << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent( _window);

    // Load glad
    if (!gladLoadGLLoader( ( GLADloadproc) glfwGetProcAddress) )
    {
        std::cout << "failed to init GLAD" << std::endl;
        glfwTerminate();
    }

    // Config view and sizecallback
    glViewport( 0, 0, _width, _height);
    glfwSetFramebufferSizeCallback(_window, fb_size_callback);
}

// Deal with ending
Glch::~Glch()
{
    glfwTerminate();
}

// Return window
GLFWwindow * Glch::win()
{
    return _window;
}

// Create shader program
int Glch::addShader( const char *vsp, const char *fsp )
{
    _shader.push_back(Shader(vsp, fsp));
    return _shader.size() - 1;
}

// Using this shader program
void Glch::use(int n )
{
    _shader[n].use();
}

// Return shader program id
unsigned int Glch::id(int n)
{
    return _shader[n].id();
}

// Window size changing call back
void fb_size_callback(GLFWwindow * window, int width, int height)
{
    glViewport(0, 0, width, height);
    window = nullptr;
}

// Create OpenGL object
void Glch::add( char * dataPath)
{
    vao.add(dataPath);
}

// Bind OpenGL object
void Glch::bindVAO(int index, bool flag)
{
    vao.bind(flag);
}



#endif
