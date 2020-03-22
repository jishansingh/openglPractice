#version 440
in vec3 vs_color;
in vec2 vs_texcoord;
in vec3 vs_position;
in vec3 vs_normal;

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

out vec4 frag_color;
void main(){
	vec4 ambient_final=calcAmbient();
	vec4 diffuse_final=calcDiffuse(vs_position,lightPos0,vs_normal);
	vec4 specularFinal=calcSpecular(vs_position,lightPos0,vs_normal,camPos);
	if(border==1){
		frag_color=texture(texture0,vs_texcoord)*vec4(1.f,0.f,0.f,1.f);
		return;
	}


	//fs_color=texture(texture0,vs_texcoord)*(specularFinal+diffuse_final+ambient_final);
	float offset=1.0/300.0;
	vec2 offsets[9] = vec2[](
        vec2(-offset,  offset), // top-left
        vec2( 0.0f,    offset), // top-center
        vec2( offset,  offset), // top-right
        vec2(-offset,  0.0f),   // center-left
        vec2( 0.0f,    0.0f),   // center-center
        vec2( offset,  0.0f),   // center-right
        vec2(-offset, -offset), // bottom-left
        vec2( 0.0f,   -offset), // bottom-center
        vec2( offset, -offset)  // bottom-right    
    );

	float kernel[9]=float[](
		1, 1,1,
		1,-8,1,
		1, 1,1
	);
	vec4 sampleTex[9];
	for(int i=0;i<9;i++){
		sampleTex[i]=texture(texture0,vs_texcoord.st+offsets[i])*(specularFinal+diffuse_final+ambient_final);
	}

	vec4 fs_color=vec4(0.f);
	for(int i=0;i<9;i++){
		fs_color+=sampleTex[i]*kernel[i];
	}
	frag_color=vec4(vec3(fs_color),1.f);


	//float average=(fs_color.r+fs_color.g+fs_color.b)/3;
	//fs_color=vec4(average, average, average, 1.0);
}

