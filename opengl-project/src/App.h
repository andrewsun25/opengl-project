#pragma once
#include "GL/glew.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "glm/glm.hpp"


SpriteRenderer* Renderer;

enum class GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class App
{
public:
	
	// Game state
	GameState  State;
	GLboolean  Keys[1024];

	// Constructor/Destructor
	App(GLuint width, GLuint height, glm::vec4 backgroundColor);
	~App();
	// Initialize game state (load all shaders/textures/levels)
	void Init();
	// GameLoop
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
private:
	GLuint	   m_width, m_height;
	glm::vec4 m_backgroundColor;
};

