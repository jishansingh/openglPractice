#version 440
in vec2 fPos;

uniform sampler2D texture0;
uniform bool horizontal;
out vec4 fs_color;

uniform float weight[5] = float[] (0.227027, 0.1945946, 0.1216216, 0.054054, 0.016216);
void main(){
	vec2 texoffset=1.f/textureSize(texture0,0);
	vec3 result=texture(texture0,fPos).rgb*weight[0];
	if(horizontal){
		for(int i=1;i<5;i++){
			result+=texture(texture0, fPos + vec2(texoffset.x*i, 0.f)).rgb*weight[i];
			result+=texture(texture0, fPos - vec2(texoffset.x*i, 0.f)).rgb*weight[i];
		}
	}
	else{
		for(int i=1;i<5;i++){
			result+=texture(texture0, fPos + vec2( 0.f, texoffset.y*i)).rgb*weight[i];
			result+=texture(texture0, fPos - vec2( 0.f, texoffset.y*i)).rgb*weight[i];
		}
	}
	fs_color=vec4(result,1.f);
}
