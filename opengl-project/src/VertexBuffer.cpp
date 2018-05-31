#include "stdafx.h"
#include "VertexBuffer.h"
#include "util/Log.h"
// VertexBuffer is raw data. VertexArray ties this raw data with layout.
VertexBuffer::VertexBuffer(const void * data, GLuint size)
{
	// Gen 1 VBO and stores its id in m_rendererID
	GLCall(glGenBuffers(1, &m_rendererID));
	// only 1 VBO can be bound for each VBO type.
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
	// Sends data from CPU to a Vertex Buffer of type STATIC_DRAW.
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	Bind();
}

void VertexBuffer::Bind()
{
	m_isBound = true;
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
}

void VertexBuffer::UnBind()
{
	m_isBound = false;
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}


