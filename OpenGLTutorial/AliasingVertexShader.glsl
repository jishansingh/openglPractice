#version 440
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;


out vec3 vs_position;
out vec3 vs_normal;
out vec2 vs_texcooord;
void main(){
	vs_position=vec3(modelMatrix*vec4(aPosition,1.f));
	vs_normal=vec3(modelMatrix*vec4(-1*aNormal,1.f));
	//vs_out.vs_texcoord=aTexCoord;
	vs_texcooord=aTexCoord;
	gl_Position=projectionMatrix*viewMatrix*modelMatrix*vec4(aPosition,1.f);
}

