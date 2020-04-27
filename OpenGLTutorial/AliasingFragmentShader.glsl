#version 440
layout (location=0) out vec3 fTexture;

in vec3 vs_position;
in vec3 vs_normal;
in vec2 vs_texcooord;

uniform sampler2D texture0;


void main(){
	fTexture = texture(texture0,vs_texcooord).rgb;
}


