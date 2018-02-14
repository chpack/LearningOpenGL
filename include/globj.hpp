#ifndef GLOBJ_HPP
#define GLOBJ_HPP

#include <fstream>
#include <string>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>


class globj
{
    public:
        unsigned int VBO, VAO, EBO;
        unsigned int vboType, drawType, eboType, dataType, drawShape, indexType, dataIndex, dataSize, normalize, indexSize, stepSize;

        float *data;
        int *index;

        globj(std::string configPath, std::string verticesPath, std::string indicesPath);

        void draw();

        ~globj();
};
#endif