#include "../include/camera.hpp"

Camera::Camera(glm::vec3 pos, float angx, float angy, float dis)
{
    this->angx = angx;
    this->angy = angy;
    this->target = pos;
    this->up = glm::vec3(0.0f, 0.0f, 1.0f);
    this->dis = dis;
    this->camera = glm::normalize(glm::vec3(glm::cos(angx), glm::sin(angx), glm::tan(angy))) * dis;
}

void Camera::move(float dx, float dy, float speed)
{
    glm::vec3 direct = camera;
    direct.z = 0;
    direct = glm::normalize(direct) + glm::vec3(dx, dy, 0) * speed;
    target = target + direct;

    target = glm::vec3(dx, dy, 0.0f);
}

void Camera::contral(float left, float right, float speed)
{
    angx += left * speed;
    angy += right * speed;
    angy = angy >  1.5f ?  1.5f : angy;
    angy = angy < -1.5f ? -1.5f : angy;

    camera = glm::normalize( glm::vec3( glm::cos(angx), glm::sin(angx), glm::sin(angy))) * dis;
}

void Camera::contrald(float left, float right)
{
    //right = right < -1.5f ? -1.5f : right;
    camera = glm::normalize( glm::vec3( glm::cos(left), glm::sin(left), glm::tan(right))) * dis;
}


float* Camera::ptr()
{
    return (float*)glm::value_ptr(glm::lookAt(camera + target, target, up));
}

glm::mat4 Camera::ptrm()
{
    return glm::lookAt(camera + target, target, up);
}
