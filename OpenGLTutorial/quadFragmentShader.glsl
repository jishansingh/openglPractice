#version 440
in vec2 fPos;

uniform sampler2D texture0;

out vec4 fs_color;
void main(){
	//fs_color=vec4(1.f,0.f,0.f,1.f);
	fs_color=vec4(texture(texture0,fPos).rgb,1.f);
}
