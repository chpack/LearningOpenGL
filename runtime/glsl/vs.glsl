#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 t;

out vec3 p;
out vec2 tout;

uniform mat4 transform;

void main()
{
    p = aPos;
    tout = t *3;
    gl_Position = transform * vec4(aPos, 1.0);
}

