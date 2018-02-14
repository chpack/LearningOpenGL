#include "../include/globj.hpp"


globj::globj(std::string configPath, std::string verticesPath, std::string indicesPath)
{
    std::ifstream confFile;
    std::ifstream verticesFile;
    std::ifstream indexFile;

    confFile.open(configPath);
    verticesFile.open(verticesPath);
    indexFile.open(indicesPath);

    confFile >> std::hex >> vboType >> drawType >> eboType >> dataType >> normalize >> drawShape >> indexType >>
                std::dec >> dataIndex >> stepSize >> dataSize >> indexSize;

    data = new float[dataSize];
    for (int i = 0; i < dataSize; i++)
        verticesFile >> data[i];

    index = new int[indexSize];
    for (int i = 0; i < indexSize; i++)
        indexFile >> index[i];

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(vboType, VBO);
    glBufferData(vboType, dataSize * sizeof(float), data, drawType);

    glBindBuffer(eboType, EBO);
    glBufferData(eboType, indexSize * sizeof(int), index, drawType);

    glVertexAttribPointer(dataIndex, stepSize, dataType, normalize, stepSize * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(vboType, 0);
    glBindVertexArray(0); 
}

void globj::draw()
{
    glBindVertexArray(VAO);
    glDrawElements(drawShape, indexSize, indexType, 0);
}

globj::~globj()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}