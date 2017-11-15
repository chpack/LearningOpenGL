#ifndef GLOBJECT_CPP
#define GLOBJECT_CPP

#include "../include/globject.h"
#include <iostream>

glVAO::glVAO(int num)
{
    _vao = new unsigned int [num];
    _vbo = new unsigned int [num];
    index = 0;
    max = num;
}

glVAO::~glVAO()
{
}

void glVAO::add( char * dataPath)
{
    std::fstream pot(dataPath, std::ios::in);
    int bufftype, drawType, dataSize, pointNum, vaoNum;
    int *pos, *width, *dataType, *norm, *step, *dealt;

    pot >> bufftype >> drawType >> dataSize >> pointNum >> vaoNum;
    pos = new int[vaoNum];
    width = new int[vaoNum];
    dataType = new int[vaoNum];
    norm = new int[vaoNum];
    step = new int[vaoNum];
    dealt = new int[vaoNum];

    for (int i = 0; i < vaoNum; i ++)
        pot >> pos[i] >> width[i] >> dataType[i] >> norm[i] >> step[i] >> dealt[i];

    float * data = new float[dataSize];
    for (int i = 0; i < dataSize; i ++)
        pot >> data[i];


    /*
    pot >>  _buffT[index] >>  _drawT[index] >> _pos[index] >> _part[index] 
        >> _dataT[index] >> _norm[index] >> _step[index] >> _number[index];
    data[index] = new float[_number[index]];
    for (unsigned int i = 0; i < _number[index]; i ++)
        pot >> data[index][i];
    pot.close();
    */

    // Very normaily function to create VBO and VAO
    glGenVertexArrays(1, &_vao[index]);
    glGenBuffers(1, &_vbo[index]);
    glBindVertexArray(_vao[index]);
    glBindBuffer(bufftype, _vbo[index]);
    glBufferData(bufftype, dataSize * sizeof(float), data, drawType);
    for (int i = 0; i < vaoNum; i ++)
        glVertexAttribPointer( pos[i], width[i], dataType[i], norm[i], step[i] * sizeof(float), (void*)(dealt[i] * sizeof(float)));
    glEnableVertexAttribArray(0);
    glBindBuffer(bufftype, 0);
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
