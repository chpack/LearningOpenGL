#include "../include/manager.hpp"

int SCREEN_W = 800;
int SCREEN_H = 600;

double x = 0, y = 0, z = 0;
double cx = 0, cy = 0, cz = 0;
float dis = 3;
float px = 0, py = 0, pz = 0;
float speed = 0.10;

int keys[GLFW_KEY_LAST] = {0};

Camera cam(glm::vec3(0.0f, 0.0f, 0.0f), 0, 0, dis);

glm::vec3 up(0.0f, 0.0f, 1.0f);

void keycb(GLFWwindow*, int key, int , int action, int )
{
    keys[key] = action == GLFW_RELEASE ? 0 : keys[key];
    keys[key] = action == GLFW_PRESS ? 1 : keys[key];
}

void processInput(GLFWwindow *window)
{

    static double last = 0;
    double now = glfwGetTime();
    double d = (now - last) * 5;
    last = now;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    static double lx = -1, ly = -1;
    double thisx, thisy;


    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2))
    {
        glfwGetCursorPos(window, &thisx, &thisy);
        cam.contral((lx - thisx) / 500,-(ly - thisy) / 500, d*20);
        glfwGetCursorPos(window, &lx, &ly);
    }

    glfwGetCursorPos(window, &lx, &ly);
    cam.move(keys[GLFW_KEY_W] - keys[GLFW_KEY_S], keys[GLFW_KEY_A] - keys[GLFW_KEY_D], d);
}

void scb(GLFWwindow *, double, double yof)
{
    dis -= yof * 0.2f;
}

void windowSize(GLFWwindow *win, int w, int h)
{
    win = nullptr;
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
    glfwSetScrollCallback(wmgr.window, scb);
    glfwSetKeyCallback(wmgr.window, keycb);


    while (!glfwWindowShouldClose(wmgr.window))
    {
        processInput(wmgr.window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        


        wmgr.usePro(0);

        glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)SCREEN_W / (float)SCREEN_H, 0.1f, 100.0f);
        glm::mat4 model = glm::rotate(glm::mat4(), glm::radians((float)glfwGetTime()), glm::vec3(0.0f, 1.0f, 0.0f));
        wmgr.setUniformMat4(0, "view", cam.ptrm());
        wmgr.setUniformMat4(0, "model", model);
        wmgr.setUniformMat4(0, "proj", proj);

        wmgr.drawObj(0);

        glfwSwapBuffers(wmgr.window);
        glfwPollEvents();
    }
    return 0;
}
