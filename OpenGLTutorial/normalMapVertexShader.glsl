#version 440
layout (location=0) in vec3 aPosition;
layout (location=1) in vec3 aNormal;
layout (location=2) in vec2 aTexcoord;


uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;

out VS_OUT{
    vec3 vs_normal;
    vec2 vs_texcoord;
    vec3 vs_position;
} vs_out;

void main(){
	vs_out.vs_position=vec3(modelMatrix*vec4(aPosition,1.f));
	vs_out.vs_texcoord=aTexcoord;
	vs_out.vs_normal=vec3(modelMatrix*vec4(aNormal,1.f));
	gl_Position=projectionMatrix*viewMatrix*modelMatrix*vec4(aPosition,1.f);

}


