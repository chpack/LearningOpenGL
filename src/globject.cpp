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

tex::tex(int num)
{
    index = 0;
    texture = new unsigned int[num];
    stbi_set_flip_vertically_on_load(true);
}

tex::~tex()
{
    delete[] texture;
}

void tex::addTex(std::string path)
{
    unsigned char * data;
    int width, height, color;
    data = stbi_load(path.c_str(), &width, &height, &color, 0);

    glGenTextures(1, &(texture[index]));
    glActiveTexture(GL_TEXTURE0 + index);
    glBindTexture(GL_TEXTURE_2D, texture[index]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    index++;
}

void tex::useTex(int i, int j)
{
    glActiveTexture(GL_TEXTURE0 + j);
    glBindTexture(GL_TEXTURE_2D, texture[i]);
}
#endif
