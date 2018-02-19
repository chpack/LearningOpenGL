#include "../include/manager.hpp"

int SCREEN_W = 800;
int SCREEN_H = 600;

double x = 1, y = 1;
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    static double lx = -1, ly = -1;
    double thisx, thisy;
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2))
    {
        if (lx > 0)
        {
            glfwGetCursorPos(window, &thisx, &thisy);
            x += (lx - thisx) / 500;
            y += (ly - thisy) / 500;
        }
        glfwGetCursorPos(window, &lx, &ly);
    } else {
        lx = -1;
    }
}

void windowSize(GLFWwindow *win, int w, int h)
{
    SCREEN_W = w;
    SCREEN_H = h;
    glViewport(0, 0, w, h);
}

int main()
{
    manager wmgr(SCREEN_W, SCREEN_H, "LG");
    wmgr.addPro("data/shader/vc.glsl", "data/shader/fc.glsl");
    wmgr.addObj("data/points/configure.conf", "data/points/vertices.pnt", "data/points/indices");

    glfwSetWindowSizeCallback(wmgr.window, windowSize);

    float i = 0.0f;
    while (!glfwWindowShouldClose(wmgr.window))
    {
        processInput(wmgr.window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glm::vec3 camera = glm::vec3(glm::sin(x), glm::cos(x), y);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::mat4 view = glm::lookAt(camera, center, up);
        wmgr.usePro(0);
        // glm::mat4 view = translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -3.0));
        glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)SCREEN_W / (float)SCREEN_H, 0.1f, 100.0f);
        glm::mat4 model = glm::rotate(glm::mat4(), glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

        // draw our first triangle
        // trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
        // trans = glm::rotate(trans, glm::radians(i), glm::vec3(0.0f, 0.0f, 1.0f));
        // trans = glm::scale(trans, glm::vec3(0.5, 0.5f, 0.5));
        // unsigned int viewi = glGetUniformLocation(wmgr.programs[0].ID, "transform"); // unsigned int modeli = glGetUniformLocation(wmgr.programs[0].ID, "transform");
        // unsigned int proji = glGetUniformLocation(wmgr.programs[0].ID, "transform");

        // glUniformMatrix4fv(viewi, 1, GL_FALSE, glm::value_ptr(view));
        // glUniformMatrix4fv(modeli, 1, GL_FALSE, glm::value_ptr(model));
        // glUniformMatrix4fv(proji, 1, GL_FALSE, glm::value_ptr(proj));
        wmgr.setUniformMat4(0, "view", view);
        wmgr.setUniformMat4(0, "model", model);
        wmgr.setUniformMat4(0, "proj", proj);

        wmgr.drawObj(0);

        glfwSwapBuffers(wmgr.window);
        glfwPollEvents();
    }
    return 0;
}