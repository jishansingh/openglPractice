#version 440
layout(location=0) in vec3 aPosition;
layout(location=1) in vec3 aNormal;
layout(location=2) in vec2 aTexcoord;
layout (location = 3) in mat4 modelMatrix;

//uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;




out vec3 vs_position;
out vec3 vs_normal;
out vec2 vs_texcoord;

void main(){
	vs_position=vec3(modelMatrix*vec4(aPosition,1.f));
	//vs_texcoord=vec2(aTexcoord.x,-1*aTexcoord.y);
	vs_texcoord=aTexcoord;
	//vs_normal=aNormal;
	vs_normal=vec3(modelMatrix*vec4(aNormal,1.f));
	gl_Position=projectionMatrix*viewMatrix*modelMatrix*vec4(aPosition,1.f);
}

