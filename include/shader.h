#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
    public:
        // Init
        Shader(const GLchar * vsp, const GLchar * fsp);

        void use();

        unsigned int id();
    protected:
        unsigned int _ID;
};

#endif

