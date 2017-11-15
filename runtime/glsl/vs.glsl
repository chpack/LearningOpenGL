#version 330 core
layout (location = 0) in vec3 aPos;
out vec3 p;
uniform vec3 col;
void main()
{
    p = aPos;
    gl_Position = vec4(aPos.x+col.x-0.5,aPos.y+col.y-0.5,0.0, 1.0);
}

