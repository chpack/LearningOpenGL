#ifndef GLOBJ_HPP
#define GLOBJ_HPP

#include <fstream>
#include <string>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <stb_image.h>


class globj
{
    public:
        unsigned int VBO, VAO, EBO, tex, attrNum, step;
        int width, height, nrCh;
        unsigned int vboType, drawType, eboType, dataType, drawShape, indexType, dataIndex, dataSize, normalize, indexSize, stepSize;

        float *data;
        int *index;
        int *aLocation;
        int *aSize;
        int *aOffset;

        globj(std::string configPath, std::string verticesPath, std::string indicesPath);

        void draw();

        ~globj();
};
#endif