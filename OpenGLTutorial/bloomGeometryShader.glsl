#version 440
layout (triangles) in;
layout (triangle_strip,max_vertices=3) out;

in VS_OUT{
	vec3 vs_position;
	vec3 vs_normal;
	vec2 vs_texcoord;
} gs_in[];

out vec3 gs_position;
out vec3 gs_normal;
out vec2 gs_texcoord;

void main(){
	for(int i=0;i<3;i++){
		gl_Position = gl_in[i].gl_Position;
		gs_position = gs_in[i].vs_position;
		gs_normal   = gs_in[i].vs_normal;
		gs_texcoord = gs_in[i].vs_texcoord;
		EmitVertex();
	}
	EndPrimitive();
}

