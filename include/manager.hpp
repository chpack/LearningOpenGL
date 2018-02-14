#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

#include "shader.hpp"
#include "globj.hpp"

// Debug tool
#define dbj(x) std::cout << x << '\t' << __FILE__ << ':' << __LINE__ << std::endl;

class manager 
{
    public:
      manager(int width, int height, std::string title);
      ~manager();

      GLFWwindow *window;
      std::vector<shader> programs;
      std::vector<globj *> objects;

      void loop();

      void addPro(std::string vc, std::string sc);
      void usePro(int i);

      void addObj(std::string configPath, std::string verticesPath, std::string indicesPath);
      void drawObj(int i);
};

#endif