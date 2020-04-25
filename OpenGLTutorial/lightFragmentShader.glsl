#version 440
in vec2 fPos;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedoSpec;
uniform vec3 camPos;
out vec4 fs_color;
struct Light {
    vec3 Position;
    vec3 Color;
};
const int NR_LIGHTS = 32;
uniform Light lights[NR_LIGHTS];
void main(){
	 // retrieve data from G-buffer
    vec3 FragPos = texture(gPosition, fPos).rgb;
    vec3 Normal = texture(gNormal, fPos).rgb;
    vec3 Albedo = texture(gAlbedoSpec, fPos).rgb;
    
    // then calculate lighting as usual
    vec3 lighting = Albedo * 0.1; // hard-coded ambient component
    vec3 viewDir = normalize(camPos - FragPos);
    for(int i = 0; i < NR_LIGHTS; ++i)
    {
        // diffuse
        vec3 lightDir = normalize(vec3(4.f)+lights[i].Position - FragPos);
        float distance = length(lightDir);
        vec3 diffuse = max(dot(normalize(Normal), lightDir), 0.0)/(distance*distance) * Albedo * lights[i].Color;
        lighting += diffuse;
    }
    fs_color = vec4(lighting, 1.0);
}
