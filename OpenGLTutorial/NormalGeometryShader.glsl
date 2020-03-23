#version 440

layout (triangles) in;
layout (line_strip,max_vertices=2) out;


in VS_OUT{
    vec3 vs_normal;
    vec3 vs_texcoord;
    vec3 vs_position;
}gs_in[];

out vec3 gs_normal;
out vec3 gs_texcoord;
out vec3 gs_position;


uniform float time;

vec3 GetNormal()
{
   vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
   vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
   return normalize(cross(a, b));
}  


vec4 explode(vec4 position, vec3 normal)
{
    float magnitude = 0.15;
    vec3 direction = normal * ((sin(time) + 1.0) / 2.0) * magnitude; 
    return position + vec4(direction, 0.0);
} 

void main(){
    
    /*
    gl_Position = position + vec4(-0.2, -0.2, 0.0, 0.0);    // 1:bottom-left
    EmitVertex();   
    gl_Position = position + vec4( 0.2, -0.2, 0.0, 0.0);    // 2:bottom-right
    EmitVertex();
    gl_Position = position + vec4(-0.2,  0.2, 0.0, 0.0);    // 3:top-left
    EmitVertex();
    gl_Position = position + vec4( 0.2,  0.2, 0.0, 0.0);    // 4:top-right
    EmitVertex();
    gl_Position = position + vec4( 0.0,  0.4, 0.0, 0.0);    // 5:top
    gs_Color=vec3(1.f,0.f,0.f);*/

    vec4 avg=(gl_in[0].gl_Position+gl_in[1].gl_Position)/2;
    gl_Position=avg;
    EmitVertex();
    gl_Position=avg+vec4(GetNormal(),0.f);
    EmitVertex();
    EndPrimitive();
}
