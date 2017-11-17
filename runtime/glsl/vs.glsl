#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 t;
out vec3 p;
out vec2 tout;
uniform vec3 col;
void main()
{
    p = aPos;
    tout = t;
    gl_Position = vec4(aPos.x+col.x-0.5,aPos.y+col.y-0.5,0.0, 1.0);
}

