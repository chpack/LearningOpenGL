#include "../include/glch.h"

void processInput(GLFWwindow * window);

int main()
{
    Glch glch( 500, 500,  "First");
    glch.addPro("runtime/glsl/vs.glsl","runtime/glsl/fs.glsl");
    glch.addVAO("./runtime/data/point/tra.pnt");
    glch.addTex("runtime/res/wall.jpg");
    glch.addTex("runtime/res/smell.jpg");


    unsigned int tfl = glGetUniformLocation(glch.id(), "transform");
    unsigned int vi = glGetUniformLocation(glch.id(), "view");
    unsigned int pr = glGetUniformLocation(glch.id(), "proj");
    unsigned int mo = glGetUniformLocation(glch.id(), "model");
    while(!glfwWindowShouldClose( glch.win()))
    {
        processInput(glch.win());
        glClearColor(0.5,0.3,0.7,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glm::mat4 trans;
        glm::mat4 model;
        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        
        glm::mat4 view;
        view = glm::translate(view, glm::vec3(0.0, 0.0, -3.0));

        glm::mat4 project;
        project = glm::perspective(glm::radians(45.0f), (float)glch.width()/ glch.height(), 0.1f, 100.0f);
        //trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0,0.0,1.0));
        //trans = glm::translate(trans, glm::vec3(0.5, -0.5, 0.0));
        trans = glm::scale(trans, glm::vec3(0.5,0.5,0.5));

        glch.usePro();
        glch.unif("tex", 0);
        glch.unif("tex2", 1);
        glUniformMatrix4fv(tfl, 1, GL_FALSE, glm::value_ptr(trans));
        glUniformMatrix4fv(vi, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(mo, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(pr, 1, GL_FALSE, glm::value_ptr(project));
        glch.useVAO(0, true);
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
