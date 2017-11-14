#ifndef GLOBJECT_CPP
#define GLOBJECT_CPP

#include "../include/globject.h"
#include <iostream>

glVAO::glVAO(int num)
{
    _vao = new unsigned int [num];
    _vbo = new unsigned int [num];
    _buffT = new unsigned int [num];
    _drawT = new unsigned int [num];
    _pos = new unsigned int [num];
    _part = new unsigned int [num];
    _dataT = new unsigned int [num];
    _norm = new unsigned int [num];
    _step = new unsigned int [num];
    _number = new unsigned int [num];
    index = 0;
    max = num;
}

glVAO::~glVAO()
{
    delete[] data;
}

void glVAO::add( char * dataPath)
{
    std::fstream pot(dataPath, std::ios::in);
    pot >>  _buffT[index] >>  _drawT[index] >> _pos[index] >> _part[index] 
        >> _dataT[index] >> _norm[index] >> _step[index] >> _number[index];
    data = new float[_number[index]];
    for (unsigned int i = 0; i < _number[index]; i ++)
        pot >> data[i];
    pot.close();

    // Very normaily function to create VBO and VAO
    glGenVertexArrays(1, &_vao[index]);
    glGenBuffers(1, &_vbo[index]);
    glBindVertexArray(_vao[index]);
    glBindBuffer(_buffT[index], _vbo[index]);
    glBufferData(_buffT[index], _number[index] * sizeof(float), data, _drawT[index]);
    glVertexAttribPointer( _pos[index], _part[index], _dataT[index], _norm[index], _step[index] * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(_buffT[index], 0);
    glBindVertexArray(0);
}

    
void glVAO::bind(int index, bool flag)
{
    if (flag)
        glBindVertexArray(_vao[index]);
    else
        glBindVertexArray(0);
}
#endif
