#ifndef GLCH_H
#define GLCH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <fstream>
#include "shader.h"
#include "globject.h"
#include "stb_image.h"

class Glch
{
    public:
        // Init for glfw and create a window 
        Glch( int width = 1280, int height=720, std::string title = (char *) "text", int objectNum = 1);

        // Dectroy anything
        ~Glch();

        // Return GLFWwindow
        GLFWwindow * win();

        // Define vertex shader and fragment shader
        int addPro(const char * vsp, const char *fsp);

        // Use the shader program
        void usePro(int index = 0);

        // Unif
        void  unif(std::string, int);
        
        // Return the id of shader program
        unsigned int id( int n = 0);

        // Create OpenGL object
        void addVAO( std::string );

        // Create OpenGL object 
        void useVAO(int , bool);
        
        // Add a object
        void addObj(void (* draw)(), int , int);
        friend void drawObj(Glch &);

        // Start main loop
        void startMainLoop();
    protected:
        // The window will be used
        GLFWwindow * _window;
        
        // The shader program
        std::vector<Shader>  _shader;
        
        // The opengl object
        glVAO vao;
        
        // Width and heighe of window
        int _width, _height;
        
        // window's title
        std::string _title;

        // Objects will be draw
        object * _start = nullptr;
        object * _end = nullptr;

        // Thread will be used to draw
        std::thread * mainLoop = nullptr;
};


#endif


