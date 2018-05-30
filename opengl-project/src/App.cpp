#include "stdafx.h"
#include "App.h"
#include "glm/glm.hpp"

App::App(GLuint width, GLuint height, glm::vec4 backgroundColor)
	:State(GameState::GAME_ACTIVE), Keys(), m_width(width), m_height(height),
	m_backgroundColor(backgroundColor)
{
}

App::~App()
{
	delete Global::Renderer;
}

void App::Init()
{
	ResourceManager& resourceManager = ResourceManager::getInstance();
	ShaderProgramSource shaderSource = resourceManager.ParseShaderSource("res/shaders/Basic.shader");
	Shader shader(shaderSource.vertexSource, shaderSource.fragmentSource);
	Global::Renderer = new SpriteRenderer(shader);
}

void App::ProcessInput(GLfloat dt)
{
}

void App::Update(GLfloat dt)
{
}

void App::Render()
{

	Global::Renderer->DrawSprite()
}
