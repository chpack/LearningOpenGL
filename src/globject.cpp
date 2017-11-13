#ifndef GLOBJECT_CPP
#define GLOBJECT_CPP

#include "../include/globject.h"
#include <iostream>

/* Read data from file
buffer::buffer(char * dataPath)
{
    std::fstream pot(dataPath, std::ios::in);
    int drawType, num;
    pot >>  _buffType >>  drawType >> _pos >> _part 
        >> _dataType >> _norm >> _step >> num;
    data = new float[num];
    for (int i = 0; i < (int)num; i ++)
        pot >> data[i];
    pot.close();
}
buffer::~buffer()
{
    delete[] data;
}

// Create a VBO to send data to GPU
glVBO::glVBO(char * pointFilePath)
{
    // Nomarily create a vbo
    glGenBuffers(1, & _vbo);
    glBindBuffer(_buffType, _vbo);
    glBufferData(_buffType, sizeof(float), data, drawType);
    glBindBuffer(_buffType, 0);
    
    std::cout << "eeeeeeeeeeeeeeeeeeeee" << std::endl;
}

glVBO::~glVBO()
{
    std::cout << "fffffffffffffffffffff" << std::endl;
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
*/
glVAO::glVAO()
{
    /*
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
    */
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

    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glBindVertexArray(_vao);

    glBindBuffer(_buffType, _vbo);
    glBufferData(_buffType, _num * sizeof(float), data, _drawType);

    glVertexAttribPointer( _pos, _part, _dataType, _norm, _step * sizeof(float), (void*)0);
    std::cout << _buffType << ' '<<_drawType << ' ' <<  _dataType   << std::endl;
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
