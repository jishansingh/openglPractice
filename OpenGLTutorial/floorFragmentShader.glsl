#version 440

in vec3 vs_position;
in vec3 vs_normal;
in vec2 vs_texcoord;
in vec4 vs_lightPos;

uniform sampler2D depthMap;
uniform sampler2D diffTex;

uniform vec3 camPos;
uniform vec3 lightPos0;

out vec4 fs_color;

//uniform mat4 lightMatrix;

vec4 calcAmbient(){
	return vec4(0.1f,0.1f,0.1f,1.f);
	//return vec4(1.f,1.f,1.f,1.f);
}
vec4 calcDiffuse(vec3 position,vec3 lightPos,vec3 normal){
	vec3 norm_normal=normalize(normal);
	vec3 posToLightVec=normalize(lightPos-position);
	float diffuse=clamp(dot(posToLightVec,norm_normal),0,1);
	vec4 diffuse_final=vec4(1.f,1.f,1.f,1.f)*diffuse;
	return diffuse_final;
}
vec4 calcSpecular(vec3 position,vec3 lightPos,vec3 normal,vec3 camPosition){
	vec3 posToLightVec=normalize(lightPos-position);
	vec3 norm_normal=normalize(normal);
	vec3 posToCamVec=normalize(camPosition-position);
	vec3 halfwayVec=normalize(posToCamVec+posToLightVec);
	vec3 reflectVec=normalize(reflect(-posToLightVec,norm_normal));
	float spec_const=pow(clamp(dot(norm_normal,halfwayVec),0,1),30);
	//float spec_const=pow(clamp(dot(posToCamVec,reflectVec),0,1),8);
	vec4 spec_final=vec4(1.f,1.f,1.f,1.f)*spec_const;
	return spec_final;
}

float calcShadow(vec4 position){
	vec3 projCoords=position.xyz;
	projCoords=projCoords*0.5+0.5;

	float closestDepth = texture(depthMap, projCoords.xy).r; 
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    // check whether current frag pos is in shadow
	float bias=-0.005;
    float shadow = currentDepth+bias > closestDepth  ? 1.0 : 0.0;

    return shadow;

}

void main(){
	vec4 ambientFinal=calcAmbient();
	vec4 diffuseFinal=calcDiffuse(vs_position,lightPos0,vs_normal);
	vec4 specFinal=calcSpecular(vs_position,lightPos0,vs_normal,camPos);
	//fs_color=texture(diffTex,vs_texcoord)*(ambientFinal+diffuseFinal+specFinal);
	//vec3 gamma=vec3(1.f/2.2f);
	//fs_color=vec4(pow(fin_color.rgb,gamma),1.f);
	float shadow=calcShadow(vs_lightPos);
	//fs_color=vec4(vec3(texture(depthMap,vs_texcoord).r),1.f);
	fs_color=texture(diffTex,vs_texcoord)*(ambientFinal+(1-shadow)*(diffuseFinal+specFinal));
	//fs_color=vec4(1.f,0.f,0.f,1.f);
}


