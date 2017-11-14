#ifndef GLOBJECT_H
#define GLOBJECT_H

#include <fstream>
#include <glad/glad.h>

// Buffer data for VBO and VAO
class glVAO
{
    public:
        glVAO(int);
        ~glVAO();
        void add(char *);
        void bind(int, bool flag = true);
    protected:
        unsigned int 
          * _vao, 
          * _vbo,
          * _buffT,
          * _drawT,
          * _pos,
          * _part,
          * _dataT,
          * _norm,
          * _step,
          * _number,
            index,
            max;
        float * data;
};
#endif
