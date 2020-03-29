#version 440
layout(location=0) in vec3 aPosition;
layout (location=1) in vec3 aNormal;
layout (location=2) in vec2 aTexcoord;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
/*
out VS_OUT{
	vec3 vs_position;
	vec3 vs_normal;
	vec2 vs_texcoord;
} gs_out;
*/

out vec3 vs_position;
out vec3 vs_normal;
out vec2 vs_texcoord;
void main(){
	vs_normal=vec3(modelMatrix*vec4(aNormal,1.f));

	vs_position=vec3(modelMatrix*vec4(aPosition,1.f));

	vs_texcoord=aTexcoord;
	//vs_normal=aNormal;
	
	//gl_Position=projectionMatrix*viewMatrix*(modelMatrix*explode(aPosition,aNormal));
	gl_Position=projectionMatrix*viewMatrix*(modelMatrix*vec4(aPosition,1.f));
}
