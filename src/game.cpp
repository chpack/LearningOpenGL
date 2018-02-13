#include "../include/manager.hpp"

const unsigned int SCREEN_W = 800;
const unsigned int SCREEN_H = 600;

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main()
{
    manager wmgr(SCREEN_W, SCREEN_H, "LG");
    wmgr.addPro("data/shader/vc.glsl", "data/shader/fc.glsl");
    wmgr.addObj("data/points/configure.conf", "data/points/vertices.pnt", "data/points/indices");

    while ( !glfwWindowShouldClose(wmgr.window))
    {
        processInput(wmgr.window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        wmgr.programs[0].use();

        wmgr.drawObj(0);

        glfwSwapBuffers(wmgr.window);
        glfwPollEvents();
    }
    return 0;
}