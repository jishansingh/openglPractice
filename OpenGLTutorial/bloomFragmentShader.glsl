#version 440
layout (location=0) out vec3 fragColor;
layout (location=1) out vec3 brightTex;

in vec3 gs_position;
in vec3 gs_normal;
in vec2 gs_texcoord;


uniform vec3 camPos;
uniform vec3 lightPos0;
uniform sampler2D diffTex;

vec4 calcAmbient(){
	return vec4(0.1f,0.1f,0.1f,1.f);
	//return vec4(1.f,1.f,1.f,1.f);
}
float getPositive(float a){
	/*if(a<0.1&&a>-0.1){
		return 1.f;
	}
	return 0.f;
	return a;*/
	if(a>0){
		return a;
	}
	else{
		return -1*a;
	}
}
vec4 calcDiffuse(vec3 position,vec3 lightPos,vec3 normal){
	vec3 norm_normal=normalize(normal);
	vec3 posToLightVec=normalize(lightPos-position);
	float diffuse=clamp(getPositive(dot(norm_normal,posToLightVec)),0,1);
	//float diffuse=max(dot(norm_normal,posToLightVec),0);
	vec4 diffuse_final=vec4(1.f,1.f,1.f,1.f)*diffuse;
	return diffuse_final;
}
vec4 calcSpecular(vec3 position,vec3 lightPos,vec3 normal,vec3 camPosition){
	vec3 posToLightVec=normalize(lightPos-position);
	vec3 norm_normal=normalize(normal);
	vec3 posToCamVec=normalize(camPosition-position);
	vec3 reflectVec=normalize(reflect(-posToLightVec,norm_normal));
	float spec_const=pow(clamp(dot(reflectVec,posToCamVec),0,1),50);
	vec4 spec_final=vec4(1.f,1.f,1.f,1.f)*spec_const;
	//return vec4(1.f,1.f,1.f,1.f);
	return spec_final;
}

//out vec4 fs_color;
void main(){
	vec4 fs_color;
	vec4 ambient_final=calcAmbient();
	vec3 tex_normal;
	 tex_normal=gs_normal;
	//vec3 tex_normal=texture(normalTex,gs_texcoord).xyz;
	vec4 diffuse_final=calcDiffuse(gs_position,lightPos0,tex_normal);
	vec4 specularFinal=calcSpecular(gs_position,lightPos0,tex_normal,camPos);
	float distance = length(gs_position-lightPos0);
	fs_color=texture(diffTex,gs_texcoord)*((specularFinal*10.f+diffuse_final*100.f)/distance+ambient_final);
	float brightness = dot(fs_color.rgb, vec3(0.2126, 0.7152, 0.0722));
	
	if(brightness>1.0){
		brightTex=vec3(fs_color);
	}
	else{
		brightTex=vec3(0.f,0.f,0.f);
	}
	fragColor=vec3(fs_color);
	//fs_color=texture(diffTex,gs_texcoord);
	//fs_color=vec4(0.f,1.f,0.f,1.f);

}

