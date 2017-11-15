#include "../include/glch.h"

void processInput(GLFWwindow * window);

int main()
{
    Glch glch( 500, 500, (char *) "First", 1);
    glch.addPro("runtime/glsl/vs.glsl","runtime/glsl/fs.glsl");
    glch.addVAO((char *)"./runtime/data/point/tra.pnt");

    int vcl = glGetUniformLocation(glch.id(), "col");

    float r = 1.0, g=1.0, b=1.0;
    int ar = 1, ab = 1, ag = 1;
    while(!glfwWindowShouldClose( glch.win()))
    {
        processInput(glch.win());
        glClearColor(r,g,b,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ar = r < 1.0f && r > 0.0f ? ar : -ar;
        ag = g < 1.0f && g > 0.0f ? ag : -ag;
        ab = b < 1.0f && b > 0.0f ? ab : -ab;
        r += ar * 0.002;
        g += ag * 0.0035;
        b += ab * 0.005;

        glch.usePro();
        glUniform3f( vcl, 1 - r, 1 - g,  1 - b);
        glch.useVAO(0, true);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers( glch.win());
        glfwPollEvents();
    }
    return 0;
}

void processInput(GLFWwindow * window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
