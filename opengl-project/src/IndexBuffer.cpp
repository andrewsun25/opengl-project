#include "stdafx.h"
#include "IndexBuffer.h"
#include <GL/glew.h>
#include "util/Log.h"

IndexBuffer::IndexBuffer(const unsigned int * data, unsigned int count)
	: m_count(count), m_isBound(false)
{
	// Gen 1 EBO and stores its id in m_rendererID
	GLCall(glGenBuffers(1, &m_rendererID));
	// only 1 EBO can be bound for each EB type.
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
	// Sends data from CPU to a Element Buffer of type STATIC_DRAW.
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
	unbind();
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_rendererID));
}

void IndexBuffer::bind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
	m_isBound = true;
}

void IndexBuffer::unbind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	m_isBound = false;
}


