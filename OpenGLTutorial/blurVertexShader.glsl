#version 440
layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec3 vNormal;
layout (location = 2) in vec2 vTexcoord;


uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;

out vec2 fPos;
void main(){
	fPos=vTexcoord;
	gl_Position=modelMatrix*vec4(vPosition,1.f);
}
