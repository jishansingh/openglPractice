#version 440 core
in vec4 FragPos;

/*
float LinearizeDepth(float depth)
{
    float z = depth * 2.0 - 1.0; // Back to NDC 
    float near_plane=0.1f;
    float far_plane=100.f;
    return (2.0 * near_plane * far_plane) / (far_plane + near_plane - z * (far_plane - near_plane));
}

void main()
{             
    float depthValue = texture(depthMap, TexCoords).r;
    FragColor = vec4(vec3(LinearizeDepth(depthValue) / far_plane), 1.0); // perspective
    // FragColor = vec4(vec3(depthValue), 1.0); // orthographic
}  
*/

uniform vec3 lightPos0;

void main()
{
    float lightDistance=length(FragPos.xyz-lightPos0);
    lightDistance=lightDistance/100.f;
    gl_FragDepth = lightDistance;
    //gl_FragDepth = LinearizeDepth(gl_FragCoord.z)/100.f;
}