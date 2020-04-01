#version 440

layout (triangles) in;
layout (triangle_strip,max_vertices=3) out;

in VS_OUT{
	vec3 vs_position;
	vec3 vs_normal;
	vec2 vs_texcoord;
} gs_in[];

uniform float time;
out vec3 gs_position;
out vec3 gs_normal;
out vec2 gs_texcoord;

/*
vec4 explode(vec3 position,vec3 normal){
	float move=(sin(time)+1.f)/2.f;
	vec4 fin=vec4(position+normalize(normal)*move,1.f);
	return fin;
}
*/

vec4 explode(vec4 position, vec3 normal)
{
    float magnitude = 2.0;
    vec3 direction = normal * ((sin(0) + 1.0) / 2.0) * magnitude; 
    //return position + vec4(direction, 0.0);
	return position;
}
vec3 GetNormal()
{
   vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
   vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
   return normalize(cross(a, b));
}  
void main(){
	vec3 normal=GetNormal();
	gl_Position=explode(gl_in[0].gl_Position, normal);
	gs_texcoord=gs_in[0].vs_texcoord;
	gs_normal = normal;
	gs_position=gs_in[0].vs_position;
	EmitVertex();
	gl_Position=explode(gl_in[1].gl_Position, normal);
	gs_texcoord=gs_in[1].vs_texcoord;
	gs_normal = normal;
	gs_position=gs_in[1].vs_position;
	EmitVertex();
	gl_Position=explode(gl_in[2].gl_Position, normal);
	gs_texcoord=gs_in[2].vs_texcoord;
	gs_normal = normal;
	gs_position=gs_in[2].vs_position;
	EmitVertex();
	EndPrimitive();

}


