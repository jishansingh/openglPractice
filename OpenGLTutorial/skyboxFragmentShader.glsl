#version 440
in vec2 vs_texcoord;
in vec3 vs_position;
//in vec3 vs_normal;


//uniform samplerCube texture0;
uniform sampler2D texture0;
uniform vec3 camPos;
uniform vec3 lightPos0;
uniform int border;


vec4 calcAmbient(){
	return vec4(0.1f,0.1f,0.1f,1.f);
}
vec4 calcDiffuse(vec3 position,vec3 lightPos,vec3 normal){
	vec3 norm_normal=normalize(normal);
	vec3 posToLightVec=normalize(lightPos-position);
	float diffuse=clamp(dot(norm_normal,posToLightVec),0,1);
	vec4 diffuse_final=vec4(1.f,1.f,1.f,1.f)*diffuse;
	return diffuse_final;
}
vec4 calcSpecular(vec3 position,vec3 lightPos,vec3 normal,vec3 camPosition){
	vec3 posToLightVec=normalize(lightPos-position);
	vec3 norm_normal=normalize(normal);
	vec3 posToCamVec=normalize(camPosition-position);
	vec3 reflectVec=normalize(reflect(-posToLightVec,norm_normal));
	float spec_const=pow(clamp(dot(reflectVec,posToCamVec),0,1),30);
	vec4 spec_final=vec4(1.f,1.f,1.f,1.f)*spec_const;
	return spec_final;
}

out vec4 fs_color;
void main(){
	fs_color=texture(texture0,vs_texcoord);
	//fs_color=vec4(1.f,0.f,0.f,1.f);
}