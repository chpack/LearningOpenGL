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

    //gl_Position = vec4(aPos, 1.0f);
}

vec4 quat_mult(vec4 q1, vec4 q2)
{ 
    vec4 qr;
    qr.x = (q1.w * q2.x) + (q1.x * q2.w) + (q1.y * q2.z) - (q1.z * q2.y);
    qr.y = (q1.w * q2.y) - (q1.x * q2.z) + (q1.y * q2.w) + (q1.z * q2.x);
    qr.z = (q1.w * q2.z) + (q1.x * q2.y) - (q1.y * q2.x) + (q1.z * q2.w);
    qr.w = (q1.w * q2.w) - (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z);
    return qr;
}
