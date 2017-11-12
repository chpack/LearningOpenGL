#version 330 core
out vec4 FragColor;
uniform vec3 col;
in vec3 p;
void main()
{
    if (p.x * p.x + p.y * p.y <= 0.2)
        FragColor = vec4(col, 1.0f);
    else
        FragColor = vec4(col.zyx, 1.0f);
}

