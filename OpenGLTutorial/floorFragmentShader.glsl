#version 440

in vec3 vs_position;
in vec3 vs_normal;
in vec2 vs_texcoord;
in vec4 vs_lightPos;

	
uniform sampler2D diffTex;

uniform samplerCube depthMap;

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

float LinearizeDepth(float depth)
{
    float z = depth * 2.0 - 1.0; // Back to NDC 
	float near_plane=0.1f;
	float far_plane=100.f;
    return (2.0 * near_plane * far_plane) / (far_plane + near_plane - z * (far_plane - near_plane));
}

float calcShadow(vec3 position){
	vec3 projCoords=position;
	//vec3 projCoords=position.xyz/position.w;
	//projCoords=projCoords*0.5+0.5;
	
	float shadow = 0.0;
	//vec2 texelSize=1.0/textureSize(depthMap,0);
	/*
	for(int x=-1;x<=1;x++){
		for(int y=-1;y<=1;y++){
			vec2 tex_cord=projCoords.xy+vec2(x,y)*texelSize;
			float closestDepth=texture(depthMap,tex_cord).r;
			shadow += depthObj > closestDepth? 1 : 0;
		}
	}*/

	 vec3 fragToLight = projCoords - lightPos0; 
	 float depthObj=length(fragToLight);
    float closestDepth = texture(depthMap, fragToLight).r;
	closestDepth = closestDepth*100.f;
	//float closestDepth=texture(depthMap,projCoords).r;

	shadow=depthObj-0.5 > closestDepth? 1 : 0;

    return shadow;

}

float calcFrag(vec4 pos){
	vec3 projCoord=pos.xyz/pos.w;
	float closestDepth=texture(depthMap,projCoord.xyz).r;
	closestDepth=LinearizeDepth(closestDepth)/100.f;
	float depthObj=LinearizeDepth(pos.z)/100.f;
	float shadow =  depthObj-0.5 > closestDepth ? 1 : 0;
	return shadow;
}

float calcShadow3D(vec3 fragToLight){
	float closetDepth=texture(depthMap,fragToLight).r*100.f;
	float currentDepth=length(fragToLight);
	float bias=0.05f;
	float shadow=(currentDepth-bias)>closetDepth?1.0:0.0;
	return shadow;
}
void main(){
	vec4 ambientFinal=calcAmbient();
	vec4 diffuseFinal=calcDiffuse(vs_position,lightPos0,vs_normal);
	vec4 specFinal=calcSpecular(vs_position,lightPos0,vs_normal,camPos);
	//fs_color=texture(diffTex,vs_texcoord)*(ambientFinal+diffuseFinal+specFinal);
	//vec3 gamma=vec3(1.f/2.2f);
	//fs_color=vec4(pow(fin_color.rgb,gamma),1.f);
	//float shadow=calcShadow(vs_position);
	vec3 fragToLight = vs_position - lightPos0;
	float shadow=calcShadow3D(fragToLight);
	//fs_color=vec4(,1.f);
	fs_color=texture(diffTex,vs_texcoord*2.f)*(ambientFinal+(1-shadow)*(diffuseFinal+specFinal));
	//fs_color=texture(depthMap, fragToLight);
	//fs_color=vec4(1.f,0.f,0.f,1.f);
	//fs_color=
}


