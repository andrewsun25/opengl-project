#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int m_rendererID;
	
public:
	bool m_isBound;
	VertexArray();
	virtual ~VertexArray();
	void addVertexBuffer(VertexBuffer& vb, const VertexBufferLayout& layout);
	void addIndexBuffer(IndexBuffer& ib);
	void bind();
	void unbind();
};

