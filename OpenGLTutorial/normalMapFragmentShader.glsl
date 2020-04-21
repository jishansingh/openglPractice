#version 440
in vec3 gs_normal;
in vec2 gs_texcoord;
in vec3 gs_position;


//uniform samplerCube texture0;
uniform vec3 camPos;
uniform vec3 lightPos0;
uniform int border;
uniform bool norm;
uniform sampler2D diffTex;
uniform sampler2D normalTex;

vec4 calcAmbient(){
	return vec4(0.1f,0.1f,0.1f,1.f);
	//return vec4(1.f,1.f,1.f,1.f);
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
	return vec4(1.f,1.f,1.f,1.f);
	return spec_final;
}
out vec4 fs_color;
void main(){
	vec4 ambient_final=calcAmbient();
	vec3 tex_normal;
	if(norm){
		 tex_normal=texture(normalTex,gs_texcoord).xyz;
	}
	else{
		 tex_normal=gs_normal;
	}
	//vec3 tex_normal=texture(normalTex,gs_texcoord).xyz;
	vec4 diffuse_final=calcDiffuse(gs_position,lightPos0,tex_normal);
	vec4 specularFinal=calcSpecular(gs_position,lightPos0,tex_normal,camPos);
	fs_color=texture(diffTex,gs_texcoord)*((specularFinal+diffuse_final)+ambient_final);
}

