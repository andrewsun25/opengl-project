#include "stdafx.h"
#include "SpriteRenderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "primitives/Vertex.h"
#include "util/util.h"
#include "VertexArray.h"
#include "glm/gtc/matrix_transform.hpp"
#include "util/Log.h"

SpriteRenderer::SpriteRenderer(const Shader& shader)
	: m_shader(shader)
{
	initRenderData();
}

void SpriteRenderer::DrawSprite(Texture & texture, glm::vec2 position, 
	glm::vec2 size, GLfloat rotate, glm::vec4 color)
{
	m_shader.Bind();
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(position, 0.0f));
	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
	// translate quad so its center is (0,0), not its bot left corner.
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
	model = glm::scale(model, glm::vec3(size, 1.0f));

	m_shader.SetUniformMat4f("u_model", model);
	m_shader.SetUniform4f("u_spriteRGBA", color.r, color.g, color.b, color.a);
	texture.Bind();
	m_quadVAO.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
}

void SpriteRenderer::initRenderData()
{
	// define (0,0) as the bottom left corner
	Vertex vertices[] = {
		// Pos      // Tex
		glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f),
		glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f),
	};
	GLuint indices[] = {
		0, 1, 2, 2, 3, 0
	};
	VertexBuffer vbo(vertices, sizeof(vertices));
	VertexBufferLayout vbLayout;
	vbLayout.push<float>(3);
	vbLayout.push<float>(2);
	m_quadVAO.AddVertexBuffer(vbo, vbLayout);
	IndexBuffer ibo(indices, NUM_ARRAY_ELEMENTS(indices));
	m_quadVAO.AddIndexBuffer(ibo);

}
