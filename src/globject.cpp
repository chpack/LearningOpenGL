#ifndef GLOBJECT_CPP
#define GLOBJECT_CPP

#include "../include/globject.h"
#include <iostream>

glVAO::glVAO(int num)
{
    _vao = new unsigned int [num];
    _vbo = new unsigned int [num];
    _ebo = new unsigned int [num];
    index = 0;
    max = num;
}

glVAO::~glVAO()
{
    for (unsigned int i = 0; i < max; i ++)
    {
        delete[] _vao;
        delete[] _vbo;
        delete[] _ebo;
    }
}

void glVAO::add( std::string dataPath)
{
    std::fstream pot(dataPath, std::ios::in);
    int bufftype, drawType, elemType, dataSize, pointNum, vaoNum, eboNum;
    int *pos, *width, *dataType, *norm, *step, *dealt;

    // Read data from file
    pot >> bufftype >> drawType >> elemType >> dataSize >> pointNum >> vaoNum >> eboNum;
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

    int * element = new int[eboNum];
    for (int i = 0; i < eboNum; i ++)
        pot >> element[i];
    pot.close();

    // Very normaily function to create VBO and VAO
    glGenVertexArrays(1, &_vao[index]);
    glGenBuffers(1, &_vbo[index]);
    glGenBuffers(1, &_ebo[index]);

    glBindVertexArray(_vao[index]);
    glBindBuffer(bufftype, _vbo[index]);
    glBindBuffer(elemType, _ebo[index]);

    glBufferData(bufftype, dataSize * sizeof(float), data, drawType);
    glBufferData(elemType, eboNum * sizeof(int), element, drawType);
    for (int i = 0; i < vaoNum; i ++)
    {
        glVertexAttribPointer( pos[i], width[i], dataType[i], norm[i], step[i] * sizeof(float), (void*)(dealt[i] * sizeof(float)));
        glEnableVertexAttribArray(i);
    }
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
