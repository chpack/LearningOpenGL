#version 330 core
out vec4 FragColor;
in vec3 p;
in vec2 tout;
uniform sampler2D tex;
uniform sampler2D tex2;
void main()
{
    if (p.x * p.x + p.y * p.y <= 0.09)
        FragColor = texture(tex2, vec2(tout.xy));
    else
        FragColor = texture(tex, vec2(tout.xy));
}

