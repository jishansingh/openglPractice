#version 440
layout(location=0) in vec3 aPosition;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
    gl_Position=(modelMatrix*vec4(aPosition,1.f));
}  


