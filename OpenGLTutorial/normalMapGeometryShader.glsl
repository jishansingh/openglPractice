#version 440

layout (triangles) in;
layout (triangle_strip,max_vertices=3) out;

in VS_OUT{
    vec3 vs_normal;
    vec2 vs_texcoord;
    vec3 vs_position;
} gs_in[];

out vec3 gs_normal;
out vec2 gs_texcoord;
out vec3 gs_position;

vec3 GetNormal()
{
   vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
   vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
   return normalize(-1*cross(a, b));
}  

void main(){
	
    vec3 normal_gs=GetNormal();
	gl_Position=gl_in[0].gl_Position;
    //gl_Position=explode(gl_in[0].gl_Position,GetNormal());
    gs_texcoord=gs_in[0].vs_texcoord;
    //gs_normal=gs_in[0].vs_normal;
    gs_normal=normal_gs;
    gs_position=gs_in[0].vs_position;
    //gs_position=vec3(gl_Position);
    EmitVertex();
    gl_Position=gl_in[1].gl_Position;
    //gl_Position=explode(gl_in[1].gl_Position,GetNormal());
    gs_texcoord=gs_in[1].vs_texcoord;
   // gs_normal=gs_in[1].vs_normal;
    gs_normal=normal_gs;
    gs_position=gs_in[1].vs_position;
    //gs_position=vec3(gl_Position);
    EmitVertex();
    gl_Position=gl_in[2].gl_Position;
    //gl_Position=explode(gl_in[2].gl_Position,GetNormal());
    //gl_Position=explode(gl_in[2].gl_Position,GetNormal());
    gs_texcoord=gs_in[2].vs_texcoord;
    //gs_normal=gs_in[2].vs_normal;
    gs_normal=normal_gs;
    gs_position=gs_in[2].vs_position;
    //gs_position=vec3(gl_Position);
    EmitVertex();

    EndPrimitive();

}