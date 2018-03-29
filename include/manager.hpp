#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>

#include "shader.hpp"
#include "globj.hpp"
#include "camera.hpp"

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
      void setUniformMat4(int i, std::string name, glm::mat4 value);

      void addObj(std::string configPath, std::string verticesPath, std::string indicesPath);
      void drawObj(int i);
};

#endif
