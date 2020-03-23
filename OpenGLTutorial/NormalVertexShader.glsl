#version 440
layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aTexcoord;
layout (location=2) in vec3 aNormal;


layout (std140) uniform Matrices
{
	mat4 viewMatrix;
	mat4 projectionMatrix;
};
uniform mat4 modelMatrix;
uniform mat4 someMat;

out VS_OUT {
	vec3 vs_normal;
    vec3 vs_texcoord;
	vec3 vs_position;
} vs_out;

out vec3 vs_texcoord;
out vec3 vs_position;
out vec3 vs_normal;

void main(){
	vs_position=vec3(modelMatrix*vec4(aPos,1.f));
	vs_texcoord=aTexcoord;
	vs_normal=aNormal;
	//vs_normal=vec3(modelMatrix*vec4(aNormal,1.f));
	//vs_normal=mat3(transpose(inverse(modelMatrix))) * aNormal;
	gl_Position=projectionMatrix*viewMatrix*modelMatrix*vec4(aPos,1.f);
	vs_out.vs_normal=vs_normal;
	vs_out.vs_texcoord=vs_texcoord;
	vs_out.vs_position=vs_position;
	gl_PointSize = 10.0;
}