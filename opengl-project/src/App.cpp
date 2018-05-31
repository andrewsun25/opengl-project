#include "stdafx.h"
#include "App.h"
#include "glm/gtc/matrix_transform.hpp"

App::App(GLuint width, GLuint height, glm::vec4 backgroundColor)
	:State(GameState::GAME_ACTIVE), Keys(), m_width(width), m_height(height),
	m_backgroundColor(backgroundColor)
{
}

App::~App()
{
	delete Renderer;
}

void App::Init()
{
	ResourceManager::LoadShader("res/shaders/sprite.shader", "sprite");
	Shader spriteShader = ResourceManager::Shaders["sprite"];
	spriteShader
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(m_width), 0.0f, static_cast<GLfloat>(m_height), -1.0f, 1.0f);
}

void App::ProcessInput(GLfloat dt)
{
}

void App::Update(GLfloat dt)
{
}

void App::Render()
{

	Renderer->DrawSprite();
}
