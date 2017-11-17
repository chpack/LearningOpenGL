#include "../include/glch.h"

void processInput(GLFWwindow * window);

int main()
{
    Glch glch( 500, 500,  "First");
    glch.addPro("runtime/glsl/vs.glsl","runtime/glsl/fs.glsl");
    glch.addVAO("./runtime/data/point/tra.pnt");

    int w, h, n;
    unsigned char *data = stbi_load("runtime/res/wall.jpg", &w, &h, &n, 0);

    unsigned int tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    int vcl = glGetUniformLocation(glch.id(), "col");

    std::cout << w << h << n;
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
        glBindTexture(GL_TEXTURE_2D, tex);
        glch.useVAO(0, true);
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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
