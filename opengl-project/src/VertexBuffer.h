#pragma once
#include <GL/glew.h>

class VertexBuffer
{
public:
	VertexBuffer(const void * data, GLuint size);
	void Bind();
	void UnBind();
	bool IsBound() const { return m_isBound; };
private:
	GLuint m_rendererID = 0;
	bool m_isBound = true;
};

