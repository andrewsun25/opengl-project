#pragma once
#include <GL/glew.h>

class VertexBuffer
{
public:
	VertexBuffer(const void * data, GLuint size);
	virtual ~VertexBuffer();
	void Bind();
	void UnBind();
	bool IsBound() const { return m_isBound; };
private:
	GLuint m_rendererID;
	bool m_isBound;
};

