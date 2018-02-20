#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 col;

uniform mat4 view;
uniform mat4 model;
uniform mat4 proj;

out vec2 Col;
void main()
{
    Col = col;
    gl_Position = proj *  view * model * vec4(aPos, 1.0);

    // gl_Position = vec4(aPos.xyz, 1.0f);
}