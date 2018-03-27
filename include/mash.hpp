#ifndef MASH_HPP
#define MASH_HPP

#include <glm/glm.hpp>
#include <vector>

struct Vertex 
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
}

struct Texture 
{
    unsigned int id;
    string type;
}

class Mesh
{
    public:
        std::vector<Vertex> vertexs;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;

        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, vector<Texture> Texture);
        void draw(Shader shader);

    private:

        unsigned int VAO, VBO, EBO;
        void setupMesh();


#endif
