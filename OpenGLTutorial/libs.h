#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

#include<glew.h>
#include<glfw3.h>
#include<glm.hpp>
#include<vec2.hpp>
#include<vec3.hpp>
#include<mat4x4.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include<SOIL2.h>


struct Vertex {
	glm::vec3 position;	
	glm::vec3 normal;
	glm::vec2 texcoord;
};
struct Vertex2 {
	glm::vec3 position;
	glm::vec2 texcoord;
};

