#ifndef GLOBJECT_CPP
#define GLOBJECT_CPP

#include "../include/globject.h"
#include <iostream>

glVAO::glVAO()
{
}

glVAO::~glVAO()
{
    delete[] data;
}

void glVAO::add( char * dataPath)
{
    std::fstream pot(dataPath, std::ios::in);
    pot >>  _buffType >>  _drawType >> _pos >> _part 
        >> _dataType >> _norm >> _step >> _num;
    data = new float[_num];
    for (int i = 0; i < (int)_num; i ++)
        pot >> data[i];
    pot.close();

    // Very normaily function to create VBO and VAO
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glBindVertexArray(_vao);
    glBindBuffer(_buffType, _vbo);
    glBufferData(_buffType, _num * sizeof(float), data, _drawType);
    glVertexAttribPointer( _pos, _part, _dataType, _norm, _step * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(_buffType, 0);
    glBindVertexArray(0);
}

    
void glVAO::bind(bool flag)
{
    if (flag)
        glBindVertexArray(_vao);
    else
        glBindVertexArray(0);
}
#endif
