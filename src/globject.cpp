#ifndef GLOBJECT_CPP
#define GLOBJECT_CPP

#include "../include/globject.h"
#include <iostream>

// Create a VBO to send data to GPU
glVBO::glVBO(char * pointFilePath)
{
    // Get data from file
    std::fstream pot(pointFilePath, std::ios::in);
    int drawType, num;
    pot >>  _buffType >>  drawType >> _pos >> _part 
        >> _dataType >> _norm >> _step >> num;
    float * data = new float[num];
    for (int i = 0; i < (int)num; i ++)
        pot >> data[i];
    pot.close();
    
    // Nomarily create a vbo
    glGenBuffers(1, & _vbo);
    glBindBuffer(_buffType, _vbo);
    glBufferData(_buffType, sizeof(float), data, drawType);
    glBindBuffer(_buffType, 0);
}

glVBO::~glVBO()
{
    glDeleteBuffers(1, &_vbo);
}
// Bind VBO, if input is false then unbind VBO
void glVBO::bind(bool flag)
{
    if (flag)
        glBindBuffer(_buffType, _vbo);
    else
        glBindBuffer(_buffType, 0);
}

glVAO::glVAO(glVBO * vbo)
{
    _vbo = vbo;
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
    _vbo -> bind();
    glVertexAttribPointer( _vbo->_pos, _vbo->_part, _vbo->_dataType,
                           _vbo->_norm, _vbo->_step * sizeof(float), (void*)0);
    std::cout << _vbo->_pos <<  _vbo->_part <<  _vbo->_dataType
                          <<  _vbo->_norm <<  _vbo->_step * sizeof(float) <<  (void*)0;
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    _vbo -> bind(false);
}

glVAO::~glVAO()
{
    glDeleteVertexArrays(1, &_vao);
}

void glVAO::bind(bool flag)
{
    if (flag)
        glBindVertexArray(_vao);
    else
        glBindVertexArray(0);
}
#endif
