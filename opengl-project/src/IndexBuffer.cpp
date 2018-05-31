#include "stdafx.h"
#include "IndexBuffer.h"
#include "util/Log.h"

IndexBuffer::IndexBuffer(const GLuint * data, GLuint count)
	: m_rendererID(0), m_count(count), m_isBound(true)
{
	// Gen 1 EBO and stores its id in m_rendererID
	GLCall(glGenBuffers(1, &m_rendererID));
	// only 1 EBO can be bound for each EB type.
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
	// Sends data from CPU to a Element Buffer of type STATIC_DRAW.
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_rendererID));
}

void IndexBuffer::Bind()
{
	m_isBound = true;
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}

void IndexBuffer::UnBind()
{
	m_isBound = false;
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}


