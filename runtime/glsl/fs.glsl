#version 330 core
out vec4 FragColor;
in vec3 p;
in vec2 tout;
uniform sampler2D tex;
uniform sampler2D tex2;
void main()
{
        FragColor = mix(texture(tex2, vec2(tout.xy)),
        texture(tex, vec2(tout.xy)),0.5);
}

