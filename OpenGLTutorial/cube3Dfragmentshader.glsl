#version 440
in vec3 gs_texcoord;
in vec3 gs_position;
in vec3 gs_normal;

uniform samplerCube texture0;
uniform vec3 camPos;
uniform vec3 lightPos0;
uniform int border;

uniform sampler2D diffTex;
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

float calcShadow(vec3 pos){
	vec3 fragToLight=pos-lightPos0;
	float currentDepth=length(fragToLight);
	float shadow  = 0.0;
	float bias    = 0.05; 
	float samples = 4.0;
	float offset  = 0.1;
	for(float x = -offset; x < offset; x += offset / (samples * 0.5))
	{
		for(float y = -offset; y < offset; y += offset / (samples * 0.5))
		{
			for(float z = -offset; z < offset; z += offset / (samples * 0.5))
			{
				float closestDepth = texture(texture0, fragToLight + vec3(x, y, z)).r; 
				closestDepth *= 100.f;   // Undo mapping [0;1]
				if(currentDepth - bias > closestDepth)
					shadow += 1.0;
			}
		}
	}
	shadow /= (samples * samples * samples);
	return shadow;
}

out vec4 fs_color;
void main(){
	/*
	if(gl_FragCoord.x<400&&gl_FragCoord.y<400){
		fs_color=vec4(1.f,0.f,0.f,1.f);
		return;
	}*/
	if(1==1){
		vec4 ambient_final=calcAmbient();
		vec4 diffuse_final=calcDiffuse(gs_position,lightPos0,gs_normal);
		vec4 specularFinal=calcSpecular(gs_position,lightPos0,gs_normal,camPos);
		float shadow=calcShadow(gs_position);
		fs_color=texture(diffTex,vec2(gs_texcoord))*((1-shadow)*(specularFinal+diffuse_final)+ambient_final);
		//fs_color=vec4(1.f);
		vec3 lightToPosVec=normalize(gs_position-camPos);
		vec3 reflectVec=reflect(lightToPosVec,normalize(gs_normal));
		float ratio=1.0/1.12;
		vec3 refractVec=refract(lightToPosVec,normalize(gs_normal),ratio);
		vec4 reflectTex=texture(texture0,reflectVec);
		vec4 refractTex=texture(texture0,refractVec);
		//fs_color=refractTex*(specularFinal+diffuse_final+ambient_final);
	}
	else{
		float depth=gl_FragCoord.z;
		fs_color=vec4(depth,depth,depth,1.f);
		gl_FragDepth = gl_FragCoord.z + 0.1;
	}
		
}
