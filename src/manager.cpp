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
    glfwTerminate();
}

void manager::loop()
{

}

void manager::addPro(std::string vc, std::string fc)
// manager::addPro(std::string vsc, std::string fsc)
{
    programs.push_back(shader(vc, fc));
}