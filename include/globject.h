#ifndef GLOBJECT_H
#define GLOBJECT_H

#include <fstream>
#include <glad/glad.h>
#include "stb_image.h"

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

class tex
{
    public:
        tex(int);
        ~tex();
        void addTex(std::string);
        void useTex(int, int);
    protected:
        int index;
        unsigned int *texture;
};

struct object
{
    object * next;
    void (* draw)();
    int vaoIndex;
    int prgIndex;
};
#endif
