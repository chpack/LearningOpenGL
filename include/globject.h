#ifndef GLOBJECT_H
#define GLOBJECT_H

#include <fstream>
#include <glad/glad.h>

// OpenGL object VBO (vertex buffer object)
class glVBO
{
    public:
        glVBO(char * pointFilePath);
        ~glVBO();
        void bind(bool flag = true);
        //void send(
        int _pos, _part, _dataType, _norm, _step;
    protected:
        unsigned int _vbo;
        int _buffType;
};

class glVAO
{
    public:
        glVAO(glVBO * vbo);
        ~glVAO();
        void bind(bool flag = true);
    protected:
        unsigned int _vao;
        glVBO * _vbo;
};
#endif
