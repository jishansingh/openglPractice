#version 440
in vec3 gs_position;
in vec3 gs_normal;
in vec2 gs_texcoord;
struct Material{
	sampler2D diffuseTex;
	sampler2D specularTex;
};

//uniform sampler2D diffTex;

uniform Material material0;
uniform Material material1;
uniform Material material2;

uniform vec3 camPos;
uniform vec3 lightPos0;
uniform int border;


vec4 calcAmbient(){
	return vec4(0.1f,0.1f,0.1f,1.f);
}
vec4 calcDiffuse(Material mat,vec3 position,vec3 lightPos,vec3 normal){
	vec3 norm_normal=normalize(normal);
	vec3 posToLightVec=normalize(lightPos-position);
	float diffuse=clamp(dot(norm_normal,posToLightVec),0,1);
	vec4 diffuse_final=texture(material0.diffuseTex,gs_texcoord)*diffuse;
	return diffuse_final;
}
vec4 calcSpecular(Material mat,vec3 position,vec3 lightPos,vec3 normal,vec3 camPosition){
	vec3 posToLightVec=normalize(lightPos-position);
	vec3 norm_normal=normalize(normal);
	vec3 posToCamVec=normalize(camPosition-position);
	vec3 reflectVec=normalize(reflect(-posToLightVec,norm_normal));
	float spec_const=pow(clamp(dot(reflectVec,posToCamVec),0,1),30);
	vec4 spec_final=texture(material0.specularTex,gs_texcoord)*spec_const;
	return spec_final;
}

out vec4 fs_color;

void main(){
	vec4 ambientFinal=calcAmbient();
	vec4 diffuseFinal=calcDiffuse(material0,gs_position,lightPos0,gs_normal);
	vec4 specFinal=calcSpecular(material0,gs_position,lightPos0,gs_normal,camPos);
	fs_color=(ambientFinal+diffuseFinal+specFinal);
	//fs_color=vec4(gs_texcoord,0.f,1.f);
}