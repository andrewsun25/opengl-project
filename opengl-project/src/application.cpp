#include "stdafx.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"
#include "primitives/Vertex.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "util/util.h"
#include "util/Log.h"
#include "ResourceManager.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// forward declare everything
static void APIENTRY glDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam);

int main(void)
{
	GLFWwindow* window;
	/* Initialize the library */
	if (!glfwInit())
		return -1;
	//Request an OpenGL 4.3 core context
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	// need to put this after glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW ERROR" << std::endl;
	}
	std::cout << glGetString(GL_VERSION) << std::endl;

		// DEBUG
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	//glm::vec3 center(SCR_WIDTH / 2.0, SCR_HEIGHT / 2.0 + 50, 0.0);
	//glm::vec2 centerTex(SCR_WIDTH / 2.0, SCR_HEIGHT / 2.0 + 50);
	//Vertex vertices[] = {
	//	// back face
	//	center + glm::vec3(-100, -200, 0), centerTex + glm::vec2(-100, -200),
	//	center + glm::vec3(100, -200, 0), centerTex + glm::vec2(100, -200),
	//	center + glm::vec3(100, 200, 0),  centerTex + glm::vec2(100, 200),
	//	center + glm::vec3(-100, 200, 0), centerTex + glm::vec2(-100, 200),
	//};

	//unsigned int indices[] = {
	//	0, 1, 2, 2, 3, 0
	//};

	//VertexArray vao;

	//VertexBuffer vbo(vertices, sizeof(vertices));
	//
	//VertexBufferLayout vbLayout;
	//vbLayout.push<float>(3); // 0th attr == position w/ 3 comp
	//vbLayout.push<float>(2); // 0th attr == position w/ 3 comp

	//vao.addVertexBuffer(vbo, vbLayout);
	//IndexBuffer ibo(indices, NUM_ARRAY_ELEMENTS(indices));
	//vao.addIndexBuffer(ibo);
	//ResourceManager& resourceManager = ResourceManager::getInstance();
	//ShaderProgramSource shaderSource = resourceManager.ParseShaderSource("res/shaders/Basic.shader");
	//Shader shader(shaderSource.vertexSource, shaderSource.fragmentSource);
	//shader.setUniform4f("u_spriteRGBA", 1.0, 1.0, 1.0, 1.0);
	//TextureSource textureSource = resourceManager.ParseTextureImage("res/textures/ferret.png");
	//Texture2D texture(textureSource.data, textureSource.width, textureSource.height, textureSource.bpp);
	//texture.Bind(0);
	//shader.setUniform1i("u_texID", 0);
	//
	//// Renderer
	//Renderer renderer;


/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		renderer.clear();



		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
	}
	glfwTerminate();
	// ends the openGL context, but stack allocated variables haven't been destructed yet.
	return 0;
}



static void APIENTRY glDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam)
{
	std::string msgSource;
	switch (source) {
	case GL_DEBUG_SOURCE_API:
		msgSource = "WINDOW_SYSTEM";
		break;
	case GL_DEBUG_SOURCE_SHADER_COMPILER:
		msgSource = "SHADER_COMPILER";
		break;
	case GL_DEBUG_SOURCE_THIRD_PARTY:
		msgSource = "THIRD_PARTY";
		break;
	case GL_DEBUG_SOURCE_APPLICATION:
		msgSource = "APPLICATION";
		break;
	case GL_DEBUG_SOURCE_OTHER:
		msgSource = "OTHER";
		break;
	}

	std::string msgType;
	switch (type) {
	case GL_DEBUG_TYPE_ERROR:
		msgType = "ERROR";
		break;
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
		msgType = "DEPRECATED_BEHAVIOR";
		break;
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
		msgType = "UNDEFINED_BEHAVIOR";
		break;
	case GL_DEBUG_TYPE_PORTABILITY:
		msgType = "PORTABILITY";
		break;
	case GL_DEBUG_TYPE_PERFORMANCE:
		msgType = "PERFORMANCE";
		break;
	case GL_DEBUG_TYPE_OTHER:
		msgType = "OTHER";
		break;
	}

	std::string msgSeverity;
	switch (severity) {
	case GL_DEBUG_SEVERITY_LOW:
		msgSeverity = "LOW";
		break;
	case GL_DEBUG_SEVERITY_MEDIUM:
		msgSeverity = "MEDIUM";
		break;
	case GL_DEBUG_SEVERITY_HIGH:
		msgSeverity = "HIGH";
		break;
	}

	printf("glDebugMessage:\n%s \n type = %s source = %s severity = %s\n", message, msgType.c_str(), msgSource.c_str(), msgSeverity.c_str());
}

void clear()
{
	GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}