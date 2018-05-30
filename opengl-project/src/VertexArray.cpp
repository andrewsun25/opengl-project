#include "stdafx.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "util/Log.h"
VertexArray::VertexArray()
	:m_isBound(false)
{
	GLCall(glGenVertexArrays(1, &m_rendererID));
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &m_rendererID));
}

// Adds without binding anything
void VertexArray::addVertexBuffer(VertexBuffer & vb, const VertexBufferLayout & layout)
{
	bind();
	vb.bind();
	const auto & attrs = layout.getAttrs();
	unsigned int offset = 0;
	for (size_t i = 0; i < attrs.size(); ++i) {
		const auto & attr = attrs[i];
		// Vertex attributes
		// i -> We are configuring the ith attribute (position, color, etc)
		// count -> The attribute has 2 components
		// type -> GL_ENUM that specifies dtype of components of attribute.
		// noramlized -> either GL_TRUE or GL_FALSE
		// stride -> space between consecutive vertices
		// (const void*)offset -> ptr to where the first occurence of that attribute is, in the array.
		// glVertexAttribPointer links the currently bound vao's ith attribute pointer with the currently bound vbo's data. 
		// That's why the last param offset is a pointer.
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, attr.count, attr.type, attr.normalized, layout.getStride(), (const void*)offset));
		offset += attr.size;
	}
}

void VertexArray::addIndexBuffer(IndexBuffer & ib)
{
	bind();
	ib.bind();
}

void VertexArray::bind()
{
	GLCall(glBindVertexArray(m_rendererID));
	m_isBound = true;
}

void VertexArray::unbind()
{
	GLCall(glBindVertexArray(0));
	m_isBound = false;
}


