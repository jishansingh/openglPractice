#include"libs.h"
#include"Shader.h"
#include"Texture.h"
#include"Mesh.h"
#include"Model.h"


void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

Vertex vertices_box[] = {
	glm::vec3(-0.5f,0.5f,0.f)   ,glm::vec3(0.f,0.f,1.f),glm::vec2(0.f,1.f),
	glm::vec3(-0.5f,-0.5f,0.0f) ,glm::vec3(0.f,0.f,1.f),glm::vec2(0.f,0.f),
	glm::vec3(0.5f,-0.5f,0.0f)  ,glm::vec3(0.f,0.f,1.f),glm::vec2(1.f,0.f),
	glm::vec3(0.5f,0.5f,0.0f)   ,glm::vec3(0.f,0.f,1.f),glm::vec2(1.f,1.f),
};

unsigned int noOfBoxVertices = sizeof(vertices_box) / sizeof(Vertex);

unsigned int indices[] = {
	0,1,2,
	0,2,3
};
unsigned int noOfIndices = sizeof(indices) / sizeof(GLuint);

float vertices[] = {
	-0.5f, -0.5f, -0.5f,-1.f,-1.f, -1.f,   0.0f,  0.0f, -1.0f,
	 0.5f, -0.5f, -0.5f, 1.f,-1.f, -1.f,   0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f, 1.f, 1.f, -1.f,   0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f, 1.f, 1.f, -1.f,   0.0f,  0.0f, -1.0f,
	-0.5f,  0.5f, -0.5f,-1.f, 1.f, -1.f,  0.0f,  0.0f, -1.0f,
	-0.5f, -0.5f, -0.5f,-1.f,-1.f, -1.f,  0.0f,  0.0f, -1.0f,

	-0.5f, -0.5f,  0.5f,-1.f,-1.f, 1.f, 0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f, 1.f,-1.f, 1.f, 0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f, 1.f, 1.f, 1.f, 0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f, 1.f, 1.f, 1.f, 0.0f,  0.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,-1.f, 1.f, 1.f, 0.0f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,-1.f,-1.f, 1.f, 0.0f,  0.0f, 1.0f,

	-0.5f,  0.5f,  0.5f,-1.f, 1.f, 1.f,	  -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f, -0.5f,-1.f, 1.f, -1.f,  -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,-1.f, -1.f, -1.f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,-1.f, -1.f, -1.f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,-1.f, -1.f, 1.f,  -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,-1.f, 1.f, 1.f,	  -1.0f,  0.0f,  0.0f,

	 0.5f,  0.5f,  0.5f,1.f, 1.f, 1.f,	   1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,1.f, 1.f, -1.f,	   1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,1.f, -1.f, -1.f,   1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,1.f, -1.f, -1.f,   1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,1.f, -1.f, 1.f,	   1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,1.f, 1.f, 1.f,	   1.0f,  0.0f,  0.0f,

	-0.5f, -0.5f, -0.5f,-1.f, -1.f, -1.f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,1.f, -1.f, -1.f,   0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,1.f, -1.f, 1.f,	   0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,1.f, -1.f, 1.f,	   0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,-1.f, -1.f, 1.f,   0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,-1.f, -1.f, -1.f,  0.0f, -1.0f,  0.0f,

	-0.5f,  0.5f, -0.5f,-1.f, 1.f, -1.f,    0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,1.f, 1.f, -1.f,	    0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,1.f, 1.f, 1.f,	    0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,1.f, 1.f, 1.f,	    0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,-1.f, 1.f, 1.f,	    0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f, -0.5f,-1.f, 1.f, -1.f,    0.0f,  1.0f,  0.0f
};


unsigned int noOfVertices = sizeof(vertices) / (9*sizeof(float));

void updateUniforms(GLFWwindow*window,Shader& shader,glm::vec3 position,glm::vec3 rotation,glm::vec3 scale,glm::vec3 camPosition,glm::vec3 lightPos0) {
	glm::mat4 modelMatrix(1.f);
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
	modelMatrix = glm::scale(modelMatrix, scale);

	//view Matrix

	glm::vec3 worldUp(0.f, 1.f, 0.f);
	glm::vec3 camFront(0.f, 0.f, -1.f);

	glm::mat4 viewMatrix(1.f);
	glm::vec3 front=glm::cross(glm::cross(worldUp, camPosition), worldUp);
	viewMatrix = glm::lookAt(camPosition, camFront, worldUp);

	//projection matrix
	float fov = 90.f;
	float nearPlane = 0.1f;
	float farPlane = 100.f;

	glm::mat4 projectionMatrix(1.f);
	int framebufferwidth;
	int framebufferheight;
	glfwGetFramebufferSize(window, &framebufferwidth, &framebufferheight);
	projectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(framebufferwidth) / framebufferheight, nearPlane, farPlane);
	shader.setUniform3f("camPos", GL_FALSE, camPosition);
	shader.setUniform3f("lightPos0", GL_FALSE, lightPos0);
	//shader.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix);
	shader.setUniformMatrix4fv("viewMatrix", GL_FALSE, viewMatrix);
	shader.setUniformMatrix4fv("projectionMatrix", GL_FALSE, projectionMatrix);
}


void updateInput(GLFWwindow* window, glm::vec3& positon) {
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		positon.z -= 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		positon.z += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		positon.x += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		positon.x -= 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
		positon.y += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
		positon.y -= 0.1f;
}

int main() {
	glfwInit();

	int glMajorVer = 4;
	int glMinorVer = 4;
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glMajorVer);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glMinorVer);
	glfwWindowHint(GLFW_RESIZABLE, true);

	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MY WINDOW", NULL, NULL);
	if (window == nullptr) {
		std::cout << "no";
		glfwTerminate();
	}

	
	//glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	int framebufferheight = WINDOW_WIDTH;
	int framebufferwidth = WINDOW_HEIGHT;
	glfwGetFramebufferSize(window, &framebufferwidth, &framebufferheight);
	glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit()!=GLEW_OK) {
		std::cout << "ok";
		glfwTerminate();
	}

	glEnable(GL_DEPTH_TEST);

	
	
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/*unsigned int ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, noOfIndices * sizeof(GLuint), indices, GL_STATIC_DRAW);
	*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9*sizeof(float),0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	
	/*glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(3);
	*/
	
	
	Shader prog_final("skyboxVertexShader.glsl", "skyboxFragmentShader.glsl", "");




	//set texture for 
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	std::string filearr[9] = {
	"right.jpg",
	"left.jpg",
	"top.jpg",
	"bottom.jpg",
	"front.jpg",
	"back.jpg"
	};
	for (int i = 0; i < 9; i++) {
		int width;
		int height;
		unsigned char*image=SOIL_load_image(("images/"+filearr[i]).c_str(), &width, &height, NULL, SOIL_LOAD_RGBA);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,image);
		//Texture texture0("images/container.png", GL_TEXTURE_2D, 0, GL_TEXTURE0);
		SOIL_free_image_data(image);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);


	//intialize matrix;
	glm::vec3 position(0.f);
	glm::vec3 rotation(0.f);
	glm::vec3 scale(1.f);

	glm::mat4 modelMatrix(1.f);
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
	modelMatrix = glm::scale(modelMatrix, scale);

	//view Matrix

	glm::vec3 worldUp(0.f, 1.f, 0.f);
	glm::vec3 camFront(0.f,0.f,-1.f);
	glm::vec3 camPosition(0.f, 0.f, 0.f);

	glm::mat4 viewMatrix(1.f);
	viewMatrix = glm::lookAt(camPosition, camFront-camPosition, worldUp);

	//projection matrix
	float fov = 90.f;
	float nearPlane = 0.1f;
	float farPlane = 100.f;

	glm::mat4 projectionMatrix(1.f);
	projectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(framebufferwidth) / framebufferheight, nearPlane, farPlane);

	prog_final.Use();
	/*
	//set uniform matrix

	glBindBuffer(GL_UNIFORM_BUFFER, ubo);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(viewMatrix));
	glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(projectionMatrix));
	*/
	prog_final.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix);
	//prog_final.setUniformMatrix4fv("viewMatrix", GL_FALSE, viewMatrix);
	//prog_final.setUniformMatrix4fv("projectionMatrix", GL_FALSE, projectionMatrix);
	
	//set uniform for lightening
	glm::vec3 lightPos0(0.f, 2.f, 3.f);
	prog_final.setUniform3f("camPos",GL_FALSE, camPosition);
	prog_final.setUniform3f("lightPos0", GL_FALSE, lightPos0);


	glEnable(GL_DEPTH_TEST);




	//for box

	unsigned int vao_box;
	glGenVertexArrays(1, &vao_box);
	glBindVertexArray(vao_box);

	unsigned int vbo_box;
	glGenBuffers(1, &vbo_box);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_box);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	//glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(normal), normal);
	//glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(normal), sizeof(texcoord), texcoord);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	Shader prog_box("cube3Dvertexshader.glsl", "cube3Dfragmentshader.glsl", "cube3DgeometryShader.glsl");

	Shader prog_normal("NormalVertexShader.glsl", "NormalFragmentShader.glsl", "NormalGeometryShader.glsl");



	//uniform buffer object
	unsigned int ubo;
	glGenBuffers(1, &ubo);
	glBindBuffer(GL_UNIFORM_BUFFER, ubo);
	glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW);

	unsigned int skyboxIndex = glGetUniformBlockIndex(prog_final.getID(), "Matrices");
	unsigned int cubeIndex = glGetUniformBlockIndex(prog_box.getID(), "Matrices");
	unsigned int NormalIndex = glGetUniformBlockIndex(prog_box.getID(), "Matrices");

	glUniformBlockBinding(prog_final.getID(), skyboxIndex, 0);
	glUniformBlockBinding(prog_box.getID(), cubeIndex, 0);
	glUniformBlockBinding(prog_normal.getID(), NormalIndex, 0);

	glBindBuffer(GL_UNIFORM_BUFFER, ubo);
	
	glBindBufferRange(GL_UNIFORM_BUFFER, 0, ubo, 0, 2 * sizeof(glm::mat4));
	
	
	//set texture for 
	unsigned int texture_box;
	glGenTextures(1, &texture_box);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture_box);
	
	for (int i = 0; i < 9; i++) {
		int width;
		int height;
		unsigned char* image = SOIL_load_image(("images/" + filearr[i]).c_str(), &width, &height, NULL, SOIL_LOAD_RGBA);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		//Texture texture0("images/container.png", GL_TEXTURE_2D, 0, GL_TEXTURE0);
		SOIL_free_image_data(image);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	//Texture texture0("images/container.png", GL_TEXTURE_2D, 0, GL_TEXTURE0);

	modelMatrix = glm::translate(modelMatrix, glm::vec3(0.f, 0.f, 0.f));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
	//prog_box.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix)
	
	prog_box.Use();
	//set uniform matrix
	//prog_box.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix);
	//prog_box.setUniformMatrix4fv("viewMatrix", GL_FALSE, viewMatrix);


	glBindBuffer(GL_UNIFORM_BUFFER, ubo);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(viewMatrix));
	glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(projectionMatrix));

	prog_box.setUniformMatrix4fv("projectionMatrix", GL_FALSE, projectionMatrix);
	prog_box.setUniformMatrix4fv("someMat", GL_FALSE, modelMatrix);

	//set uniform for lightening
	//glm::vec3 lightPos0(1.f, 0.f, 1.f);
	prog_box.setUniform3f("camPos", GL_FALSE, camPosition);
	prog_box.setUniform3f("lightPos0", GL_FALSE, lightPos0);
	prog_box.setUniform1f("time", 0.f);

	/*
	prog_normal.Use();
	glBindBuffer(GL_UNIFORM_BUFFER, ubo);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(viewMatrix));
	glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(projectionMatrix));

	prog_final.Use();
	//set uniform matrix

	glBindBuffer(GL_UNIFORM_BUFFER, ubo);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(viewMatrix));
	glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(projectionMatrix));
	*/
	Shader nanosuit("loaderVertexShader.glsl", "loaderFragmentShader.glsl", "loaderGeometryFragment.glsl");

	Model mod("objFile/nanosuit/nanosuit.obj");

	/*
	std::vector<Texture>diffTex;
	std::vector<Texture>specTex;
	std::vector<Vertex>vert_vec;
	std::vector<GLuint>index_vec;
	for (int i = 0; i < noOfBoxVertices; i++) {
		vert_vec.push_back(vertices_box[i]);
	}
	for (int i = 0; i < noOfIndices; i++) {
		index_vec.push_back(indices[i]);
	}
	Texture texture0("images/top.jpg",GL_TEXTURE_2D,0);
	diffTex.push_back(texture0);
	//specTex.push_back(texture0);
	Mesh mesh(vert_vec, index_vec, diffTex, specTex);
	*/
	updateUniforms(window, nanosuit, position, rotation, scale,camPosition, lightPos0);
	

	//planet

	Shader planet("planetVertexShader.glsl", "planetFragmentShader.glsl", "planetGeometryShader.glsl");

	Model plan("objFile/planet/planet.obj");
	updateUniforms(window, planet, position, rotation, scale, camPosition, lightPos0);

	Shader rockShader("rockVertexShader.glsl", "rockFragmentShader.glsl", "");

	Model rock("objFile/rock/rock.obj");
	updateUniforms(window, rockShader, glm::vec3(-0.5f,0.f,0.f), rotation, scale, camPosition, lightPos0);


	/*
	const int amount = 10;
	glm::mat4* matrices;
	srand(glfwGetTime());
	matrices =new glm::mat4[amount];

	int radius = 0.f;
	int offset = 1.f;


	for (int i = 0; i < amount; i++) {
		glm::mat4 mat= glm::mat4(1.f);
		glm::vec3 pos;
		float angle = (float)i / (float)amount * 360.f;
		float displacement = (rand() % (2 * offset * 100)) / 100.f - offset;
		pos.x = sin(angle) * radius + displacement;
		displacement = (rand() % (2 * offset * 100)) / 100.f - offset;
		pos.z = cos(angle) * radius + displacement;
		displacement = (rand() % (2 * offset * 100)) / 100.f - offset;
		pos.y = displacement*0.4f;
		mat = glm::translate(mat, pos);
		mat = glm::rotate(mat, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
		mat = glm::rotate(mat, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
		mat = glm::rotate(mat, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));

		
		int sc= (rand() % (100)) / 1000.f;
		glm::vec3 scale_rock(sc);
		mat = glm::scale(mat, scale_rock);
		matrices[i] = mat;
	}
	*/
	unsigned int amount = 10000;
	glm::mat4* modelMatrices;
	modelMatrices = new glm::mat4[amount];
	srand(glfwGetTime()); // initialize random seed	
	float radius = 10.f;
	float offset = 2.5f;

	for (unsigned int i = 0; i < amount; i++)
	{
		glm::mat4 model = glm::mat4(1.0f);
		// 1. translation: displace along circle with 'radius' in range [-offset, offset]
		float angle = (float)i / (float)amount * 360.0f;
		float displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
		float x = sin(angle) * radius + displacement;
		displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
		float y = displacement * 0.4f; // keep height of field smaller compared to width of x and z
		displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
		float z = cos(angle) * radius + displacement;
		model = glm::translate(model, glm::vec3(x, y, z));

		// 2. scale: scale between 0.05 and 0.25f
		float scale = (rand() % 20) / 100.0f + 0.05;
		model = glm::scale(model, glm::vec3(scale));

		// 3. rotation: add random rotation around a (semi)randomly picked rotation axis vector
		float rotAngle = (rand() % 360);
		model = glm::rotate(model, rotAngle, glm::vec3(0.4f, 0.6f, 0.8f));

		// 4. now add to list of matrices
		modelMatrices[i] = model;
	}


	rockShader.Use();
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, amount * sizeof(glm::mat4), &modelMatrices[0], GL_STATIC_DRAW);

	for (int i = 0; i < rock.meshes.size(); i++) {
		glBindVertexArray(rock.meshes[i].getVAO());

		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);

		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));
		glEnableVertexAttribArray(5);
		glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2*sizeof(glm::vec4)));
		glEnableVertexAttribArray(6);
		glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3*sizeof(glm::vec4)));

		glVertexAttribDivisor(3, 1);
		glVertexAttribDivisor(4, 1);
		glVertexAttribDivisor(5, 1);
		glVertexAttribDivisor(6, 1);

	}

	


	while (!glfwWindowShouldClose(window)) {
		prog_final.Use();
		glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
		glBindVertexArray(vao);

		//glEnable(GL_STENCIL_TEST);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
		glfwPollEvents();
		
		
		updateInput(window, camPosition);
		modelMatrix = glm::mat4(1.f);
		modelMatrix = glm::translate(modelMatrix, position);
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
		modelMatrix = glm::scale(modelMatrix, scale);

		viewMatrix = glm::lookAt(camPosition, camFront - camPosition, worldUp);

		
		prog_final.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix);
		//glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(viewMatrix));
		//prog_final.setUniformMatrix4fv("viewMatrix", GL_FALSE, viewMatrix);
		//prog_final.setUniform1i("border", 0);
		prog_final.setUniform3f("camPos", GL_FALSE, camPosition);
		//glEnable(GL_DEPTH_TEST);
		//glDrawArrays(GL_TRIANGLES,0,noOfVertices);
		prog_final.unUse();
		//glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
		//glDisable(GL_DEPTH_TEST);
		prog_box.Use();
		glBindVertexArray(vao_box);
		glBindTexture(GL_TEXTURE_CUBE_MAP, texture_box);
		modelMatrix = glm::mat4(1.f);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0.f,0.f,0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.10f));
		prog_box.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix);
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(viewMatrix));
		//prog_box.setUniformMatrix4fv("viewMatrix", GL_FALSE, viewMatrix);
		prog_box.setUniform3f("camPos", GL_FALSE, camPosition);
		//glEnable(GL_PROGRAM_POINT_SIZE);
		prog_box.setUniform1f("time", (float)glfwGetTime());
		//glDrawArrays(GL_TRIANGLES, 0, noOfVertices);

		prog_normal.Use();
		glBindVertexArray(vao_box);
		glBindTexture(GL_TEXTURE_CUBE_MAP, texture_box);
		modelMatrix = glm::mat4(1.f);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0.f, 0.f, 0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.10f));
		prog_normal.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix);
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(viewMatrix));
		//prog_box.setUniformMatrix4fv("viewMatrix", GL_FALSE, viewMatrix);
		prog_normal.setUniform3f("camPos", GL_FALSE, camPosition);
		//glEnable(GL_PROGRAM_POINT_SIZE);
		prog_normal.setUniform1f("time", (float)glfwGetTime());
		glDrawArrays(GL_TRIANGLES, 0, noOfVertices);

		/*
		//glBindVertexArray(mesh.getVAO());
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		nanosuit.Use();
		nanosuit.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix);
		viewMatrix = glm::lookAt(camPosition, camFront, worldUp);
		nanosuit.setUniformMatrix4fv("viewMatrix", GL_FALSE, viewMatrix);
		projectionMatrix= glm::mat4(1.f);
		projectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(framebufferwidth) / framebufferheight, nearPlane, farPlane);
		nanosuit.setUniformMatrix4fv("projectionMatrix", GL_FALSE, projectionMatrix);
		nanosuit.setUniform3f("camPos", GL_FALSE, camPosition);
		nanosuit.setUniform3f("lightPos0", GL_FALSE, lightPos0);
		//texture0.bind();
		//nanosuit.setUniform1i("diffTex", texture0.getTextureUnit());

		nanosuit.setUniform1f("time", (float)glfwGetTime());
		nanosuit.Use();
		mod.Draw(&nanosuit);
		*/

		//planet.Use();
		//updateUniforms(window, planet, glm::vec3(0.f), glm::vec3(0.f), glm::vec3(1.f), camPosition, lightPos0);
		//planet.Use();
		////planet.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix);
		//planet.setUniform1f("time", (float)glfwGetTime());
		//plan.Draw(&planet);

		
		//updateUniforms(window, rockShader, glm::vec3(-0.5f, 0.f, 0.f), rotation, glm::vec3(0.15f), camPosition, lightPos0);
		rockShader.Use();
		updateUniforms(window, rockShader, glm::vec3(-0.5f, 0.f, 0.f), rotation, glm::vec3(0.15f), camPosition, lightPos0);
		
		glActiveTexture(GL_TEXTURE0+ rock.getTexture(0)[0]->getTextureUnit());
		rockShader.setUniform1i("material0.diffuseTex", rock.getTexture(0)[0]->getTextureUnit());
		
		glBindTexture(GL_TEXTURE_2D, rock.getTexture(0)[0]->getID());
		rockShader.Use();
		rock.Draw(&rockShader);
		
		/*
		rockShader.Use();
		updateUniforms(window, rockShader, glm::vec3(-0.5f, 0.f, 0.f), rotation, glm::vec3(0.15f), camPosition, lightPos0);
		rockShader.setUniform1i("material0.diffuseTex", rock.getTexture(0)[0]->getTextureUnit());
		glActiveTexture(GL_TEXTURE0+ rock.getTexture(0)[0]->getTextureUnit());
		glBindTexture(GL_TEXTURE_2D, rock.getTexture(0)[0]->getID()); // note: we also made the textures_loaded vector public (instead of private) from the model class.
		for (unsigned int i = 0; i < rock.meshes.size(); i++)
		{
			glBindVertexArray(rock.meshes[i].getVAO());
			glDrawElementsInstanced(GL_TRIANGLES, rock.meshes[i].indices.size(), GL_UNSIGNED_INT, 0, amount);
			glBindVertexArray(0);
		}*/

		
		//updateUniforms(window, rockShader, glm::vec3(0.5f, 0.f, 0.f), rotation, glm::vec3(0.25f), camPosition, lightPos0);
		//rock.Draw(&rockShader);

		/*
		modelMatrix = glm::mat4(1.f);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0.f,0.f,0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1.1f));
		prog_final.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix);
		prog_final.setUniform1i("border", 1);
		glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
		glStencilMask(0xFF);
		glDrawElements(GL_TRIANGLES, noOfIndices, GL_UNSIGNED_INT, 0);
		*/

		glfwSwapBuffers(window);
		//glfwPollEvents();
	}
	glfwTerminate();
	return 0;

}