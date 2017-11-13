#ifndef GLCH_H
#define GLCH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "shader.h"
#include "globject.h"

class Glch
{
    public:
        // Init for glfw and create a window 
        Glch( int width = 1280, int height=720, char * title = (char *) "text");

        // Dectroy anything
        ~Glch();

        // Return GLFWwindow
        GLFWwindow * win();

        // Define vertex shader and fragment shader
        int addShader(const char * vsp, const char *fsp);

        // Use the shader program
        void use(int n = 0);

        // Create OpenGL object
        int addVBO( char *);
        void add( char * );

        // Create OpenGL object
        void bindVBO(int , bool);
        void bindVAO(int , bool);
        
        // Return the id of shader program
        unsigned int id( int n = 0);
        
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
        char *_title;
};

#endif


