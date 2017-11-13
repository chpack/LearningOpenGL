#ifndef GLOBJECT_H
#define GLOBJECT_H

#include <fstream>
#include <glad/glad.h>

// Buffer data for VBO and VAO
class glVAO
{
    public:
        glVAO();
        ~glVAO();
        void add(char *);
        void bind(bool flag = true);
    protected:
        unsigned int _vao, _vbo;
        unsigned int _buffType,
            _drawType,
            _pos,
            _part,
            _dataType,
            _norm,
            _step,
            _num;
        float * data;
};
#endif
