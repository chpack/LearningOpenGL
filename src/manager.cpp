#include "../include/manager.hpp"


// Init of opengl, glfw and glad
manager::manager(int width, int height, std::string title) 
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cout << "failled to init" << std::endl;
    }
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

// Close all
manager::~manager()
{
    for (globj *obj : objects)
        obj->~globj();
    glfwTerminate();

}

void manager::loop()
{

}

void manager::addPro(std::string vc, std::string fc)
{
    programs.push_back(shader(vc, fc));
}

void manager::usePro(int i)
{
    programs[i].use();
}

void manager::setUniformMat4(int i, std::string name, glm::mat4 value)
{
    programs[i].setMat4f(name, value);
}
void manager::addObj(std::string configPath, std::string verticesPath, std::string indicesPath)
{
    globj * tmp = new globj(configPath, verticesPath, indicesPath);
    // objects.push_back(new globj(configPath, verticesPath, indicesPath));
    objects.push_back(tmp);
}

void manager::drawObj(int i)
{
    objects[i]->draw();
}
