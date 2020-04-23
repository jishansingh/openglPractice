#include"libs.h"
#include"Shader.h"
#include"Texture.h"
#include"Mesh.h"
#include"Model.h"
#include"frameBuffer.h"

void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

float vertices_box[] = {
	-1.f, 1.f,0.f,
	-1.f,-1.f,0.f,
	 1.f,-1.f,0.f,
	 1.f, 1.f,0.f,
};

float normal[] = {
	0.f,1.f,0.f,
	0.f,1.f,0.f,
	0.f,1.f,0.f,
	0.f,1.f,0.f,
};

float texcoord[] = {
	0.f,1.f,
	0.f,0.f,
	1.f,0.f,
	1.f,1.f,
};

unsigned int quad_count= sizeof(vertices_box) / (3*sizeof(float));

GLuint indices[] = {
	0,1,2,
	2,3,0
};
unsigned int noOfIndices = sizeof(indices) / sizeof(GLuint);

float vertices[] = {
	// back face
	-1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	 1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
	 1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f, // bottom-right         
	 1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
	-1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	-1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f, // top-left
	// front face
	-1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
	 1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f, // bottom-right
	 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
	 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
	-1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f, // top-left
	-1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
	// left face
	-1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
	-1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-left
	-1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
	-1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
	-1.0f, -1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-right
	-1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
	// right face
	 1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
	 1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
	 1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-right         
	 1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
	 1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
	 1.0f, -1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-left     
	// bottom face
	-1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
	 1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // top-left
	 1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
	 1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
	-1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f, // bottom-right
	-1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
	// top face
	-1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
	 1.0f,  1.0f , 1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
	 1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f, // top-right     
	 1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
	-1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
	-1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f  // bottom-left        
};


void updateInput(GLFWwindow* window, glm::vec3& positon, glm::vec3& cameraFront, glm::vec3& cameraUp, int& norm) {
	//const float cameraSpeed = 0.01f; // adjust accordingly
	//if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	//	positon += cameraSpeed * cameraFront;
	//if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	//	positon -= cameraSpeed * cameraFront;
	//if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	//	positon -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	//if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	//	positon += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	//

	//return;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		positon.z -= 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		positon.z += 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		positon.x += 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		positon.x -= 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
		positon.y += 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
		positon.y -= 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		cameraFront.z += 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
		cameraFront.z -= 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		cameraFront.y += 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
		cameraFront.y -= 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
		cameraFront.x += 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
		cameraFront.x -= 0.01f;
	else if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
		norm = !norm;
}

unsigned int noOfVertices = sizeof(vertices) / (8 * sizeof(float));

void updateUniforms(GLFWwindow* window, Shader& shader, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, glm::vec3 camPosition, glm::vec3 lightPos0,
	glm::vec3 camFront, glm::vec3 worldUp) {
	glm::mat4 modelMatrix(1.f);
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
	modelMatrix = glm::scale(modelMatrix, scale);

	//view Matrix

	glm::mat4 viewMatrix(1.f);
	glm::vec3 front = glm::cross(glm::cross(worldUp, camPosition), worldUp);
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
	//projectionMatrix = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, nearPlane, farPlane);
	/*float near_plane = 0.1f, far_plane = 100.5f;
	glm::mat4 projectionMatrix = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);*/

	shader.setUniform3f("camPos", GL_FALSE, camPosition);
	shader.setUniform3f("lightPos0", GL_FALSE, lightPos0);
	shader.setUniformMatrix4fv("modelMatrix", GL_FALSE, modelMatrix);
	shader.setUniformMatrix4fv("viewMatrix", GL_FALSE, viewMatrix);
	shader.setUniformMatrix4fv("projectionMatrix", GL_FALSE, projectionMatrix);

	//float near_plane = 0.1f, far_plane = 100.5f;

	viewMatrix = glm::lookAt(lightPos0,
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));

	//projectionMatrix = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, nearPlane, farPlane);

	projectionMatrix = projectionMatrix * viewMatrix;
	shader.setUniformMatrix4fv("lightMatrix", GL_FALSE, projectionMatrix);

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
	if (glewInit() != GLEW_OK) {
		std::cout << "ok";
		glfwTerminate();
	}

	glEnable(GL_DEPTH_TEST);
	unsigned int cubevao;
	glGenVertexArrays(1, &cubevao);
	glBindVertexArray(cubevao);

	unsigned int cubevbo;
	glGenBuffers(1, &cubevbo);
	glBindBuffer(GL_ARRAY_BUFFER, cubevbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * noOfVertices * 8, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), ((void*)(3 * sizeof(float))));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), ((void*)(6 * sizeof(float))));
	glEnableVertexAttribArray(2);
	

	unsigned int quadvao;
	glGenVertexArrays(1, &quadvao);
	glBindVertexArray(quadvao);

	unsigned int quadvbo;
	std::cout << quad_count;
	glGenBuffers(1, &quadvbo);
	glBindBuffer(GL_ARRAY_BUFFER, quadvbo);
	glBufferData(GL_ARRAY_BUFFER, quad_count * 8 * sizeof(float), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, quad_count * 3 * sizeof(float), &vertices_box);
	glBufferSubData(GL_ARRAY_BUFFER, quad_count * 3 * sizeof(float), quad_count * 3 * sizeof(float), &normal);
	glBufferSubData(GL_ARRAY_BUFFER, quad_count * 6 * sizeof(float), quad_count * 2 * sizeof(float), &texcoord);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)(quad_count * 3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(quad_count * 6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	unsigned int quadibo;
	glGenBuffers(1, &quadibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quadibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	unsigned int quadfbo;
	glGenFramebuffers(1, &quadfbo);
	glBindFramebuffer(GL_FRAMEBUFFER, quadfbo);

	unsigned int texture2;
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, WINDOW_WIDTH, WINDOW_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//glDrawBuffer(GL_COLOR_ATTACHMENT0);
	
	//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, quadfbo, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, quadfbo);
	//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture2, 0);
	//glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture2, 0);
	//GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
	//glDrawBuffers(1, DrawBuffers);


	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "Framebuffer not complete!" << std::endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	Shader normalShader("normalMapVertexShader.glsl", "normalMapFragmentShader.glsl", "normalMapGeometryShader.glsl");
	Shader quadShader("quadVertexShader.glsl", "quadFragmentShader.glsl", "");
	Texture texture0("images/floor.png", GL_TEXTURE_2D, 1);
	//Texture texture1("images/brickwall_normal.jpg", GL_TEXTURE_2D, 0);
	glm::vec3 camPosition(0.f, 0.f, 1.f);
	glm::vec3 position(0.f, 0.f, 0.f);
	glm::vec3 rotation(0.f, 0.f, 0.f);
	glm::vec3 scale(2.f,2.f,10.f);
	glm::vec3 worldUp(0.f, 1.f, 0.f);
	glm::vec3 camFront(0.f, 0.f, 0.f);
	glm::vec3 lightPos(-2.0f, 10.0f, 1.0f);
	int norm = 0;
	normalShader.setUniform1i("norm", norm);
	while (!glfwWindowShouldClose(window)) {
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		
		
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindFramebuffer(GL_FRAMEBUFFER, quadfbo);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glClear(GL_COLOR_BUFFER_BIT);
		normalShader.Use();
		glBindVertexArray(cubevao);
		updateInput(window, camPosition, lightPos, worldUp, norm);
		updateUniforms(window, normalShader, position, rotation, scale, camPosition, lightPos, camFront, worldUp);
		normalShader.setUniform1i("norm", norm);
		normalShader.setUniform1i("diffTex", texture0.getTextureUnit());
		//normalShader.setUniform1i("normalTex", texture1.getTextureUnit());
		texture0.bind();
		//texture1.bind();
		glDrawArrays(GL_TRIANGLES, 0, noOfVertices);
		updateUniforms(window, normalShader, lightPos, rotation, glm::vec3(1.f), camPosition, lightPos, camFront, worldUp);
		normalShader.setUniform1i("diffTex", texture0.getTextureUnit());
		texture0.bind();
		//glDrawArrays(GL_TRIANGLES, 0, noOfVertices);
		glBindVertexArray(0);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT);
		quadShader.Use();
		glBindVertexArray(quadvao);
		updateUniforms(window, quadShader, glm::vec3(0.f), rotation, glm::vec3(1.f), camPosition, lightPos, camFront, worldUp);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glActiveTexture(GL_TEXTURE0);
		quadShader.setUniform1i("texture0", 0);
		glDrawElements(GL_TRIANGLES, noOfIndices, GL_UNSIGNED_INT, 0);


		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	glDeleteFramebuffers(1, &quadfbo);
	glfwTerminate();
	return 0;
}