#include "stdafx.h"
#include "App.h"
#include "glm/gtc/matrix_transform.hpp"
#include "CONSTANTS.h"
#include "SpriteRenderer.h"

SpriteRenderer* Renderer;

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
	ResourceManager::LoadShader(SPRITE_FILE, "sprite");
	Shader spriteShader(ResourceManager::GetShader("sprite"));
	ResourceManager::LoadTexture(FERRET_FILE, "ferret");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(m_width), 0.0f, static_cast<GLfloat>(m_height), -1.0f, 1.0f);
	spriteShader.SetUniform1i("u_texID", 0);
	spriteShader.SetUniformMat4f("u_proj", projection);
	Renderer = new SpriteRenderer(spriteShader);
}

void App::ProcessInput(GLfloat dt)
{
}

void App::Update(GLfloat dt)
{
}

void App::Render()
{
	Texture ferretTexture(ResourceManager::GetTexture("ferret"));
	Renderer->DrawSprite(ferretTexture,
		glm::vec2(200, 200), glm::vec2(20, 80), -45.0f, 
		glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
}
