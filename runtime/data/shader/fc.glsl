#version 330 core
in vec2 Col;
out vec4 FragColor;
void main()
{
   FragColor = vec4(Col, 0.2f, 1.0f);
}