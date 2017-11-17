#ifndef GLOBJECT_H
#define GLOBJECT_H

#include <fstream>
#include <glad/glad.h>

// Buffer data for VBO and VAO
class glVAO
{
    public:
        glVAO(int num = 8);
        ~glVAO();
        void add(std::string);
        void bind(int, bool flag = true);
    protected:
        unsigned int 
          * _vao, 
          * _vbo,
          * _ebo,
          * _potNum,
            index,
            max;
};

struct object
{
    object * next;
    void (* draw)();
    int vaoIndex;
    int prgIndex;
};
#endif
