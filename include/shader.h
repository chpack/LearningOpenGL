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
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
    protected:
        unsigned int _ID;
};

#endif

