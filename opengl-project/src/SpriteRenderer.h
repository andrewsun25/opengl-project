#pragma once
#include "Shader.h"
#include "Texture.h"
#include "glm/glm.hpp"
#include "VertexArray.h"

class SpriteRenderer
{
public:
	SpriteRenderer(const Shader &shader);
	// default dstr calls dstr of Shader and VertexArray
	void DrawSprite(Texture &texture, glm::vec2 position,
		glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f,
		glm::vec4 color = glm::vec4(1.0f));
private:
	Shader m_shader;
	VertexArray m_quadVAO;

	void initRenderData();

};

