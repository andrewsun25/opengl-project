#include "stdafx.h"
#include "VertexBuffer.h"
#include <GL/glew.h>
#include "util/Log.h"
// VertexBuffer is raw data. VertexArray ties this raw data with layout.
VertexBuffer::VertexBuffer(const void * data, unsigned int size)
	:m_isBound(false)
{
	// Gen 1 VBO and stores its id in m_rendererID
	GLCall(glGenBuffers(1, &m_rendererID));
	// only 1 VBO can be bound for each VBO type.
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
	// Sends data from CPU to a Vertex Buffer of type STATIC_DRAW.
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	unbind();
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_rendererID));
}

void VertexBuffer::bind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
	m_isBound = true;
}

void VertexBuffer::unbind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	m_isBound = false;
}


