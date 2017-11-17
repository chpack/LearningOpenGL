#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 t;

out vec3 p;
out vec2 tout;

uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    p = aPos;
    tout = t *3;
    gl_Position = proj * view * model * transform * vec4(aPos, 1.0);
}

