#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

#include "shader.hpp"
#include "globj.hpp"

class manager 
{
    public:
      manager(int width, int height, std::string title);
      ~manager();
      void loop();
      std::vector<shader> programs;

      void addPro(std::string vc, std::string sc);

      GLFWwindow *window;

      std::vector<globj *> objects;

      void addObj(std::string configPath, std::string verticesPath, std::string indicesPath);
      void drawObj(int i);
};

#endif