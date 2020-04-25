#version 440
in vec2 fPos;

uniform sampler2D texture0;
uniform sampler2D diffTex;
out vec4 fs_color;
void main(){
	//fs_color=vec4(1.f,0.f,0.f,1.f);
	//fs_color=vec4(texture(texture0,fPos).rgb,1.f);

	const float gamma = 2.2;
    vec3 hdrColor =texture(texture0,fPos).rgb;
    hdrColor += texture(diffTex,fPos).rgb;
    // reinhard tone mapping
    //vec3 mapped = hdrColor / (hdrColor + vec3(1.0));
    float exposure=2.0;
    vec3 mapped = vec3(1.f) - exp(-hdrColor*exposure);
    // gamma correction 
    //mapped = pow(mapped, vec3(1.0 / gamma));
  
    fs_color = vec4(mapped, 1.0);
}
