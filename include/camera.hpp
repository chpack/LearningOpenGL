#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
    public:
        Camera(glm::vec3 pos, float angx = 0.0f, float angy = 0.0f, float dis = 3);
        void move(float dx, float dy, float speed = 0.01f);
        void contral(float left, float right, float speed = 1.0f);
        void contrald(float left, float right);
        float* ptr();
        glm::mat4 ptrm();

    private:
        glm::vec3 target;
        glm::vec3 camera;
        glm::vec3 up;

        float dis;
        float angx, angy;
};
#endif
