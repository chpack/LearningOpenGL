#version 330 core
out vec4 FragColor;
uniform vec3 col;
in vec3 p;
void main()
{
    if (p.x * p.x + p.y * p.y <= 0.2)
        FragColor = vec4(p, 1.0f);
    else
        FragColor = vec4(col.yxz, 1.0f);
}

