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

    float i = 0.0f;
    while (!glfwWindowShouldClose(wmgr.window))
    {
        processInput(wmgr.window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        // wmgr.programs[0].use();
        glm::mat4 trans;
        // trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
        trans = glm::rotate(trans, glm::radians(i), glm::vec3(0.0f, 0.0f, 1.0f));
        i += 1;
        // trans = glm::scale(trans, glm::vec3(0.5, 0.5f, 0.5));

        unsigned int tfl = glGetUniformLocation(wmgr.programs[0].ID, "transform");
        glUniformMatrix4fv(tfl, 1, GL_FALSE, glm::value_ptr(trans));
        wmgr.usePro(0);

        wmgr.drawObj(0);

        glfwSwapBuffers(wmgr.window);
        glfwPollEvents();
    }
    return 0;
}