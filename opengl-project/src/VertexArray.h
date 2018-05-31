#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
public:
	VertexArray();
	void AddVertexBuffer(VertexBuffer& vb, const VertexBufferLayout& layout);
	void AddIndexBuffer(IndexBuffer& ib);
	void Bind();
	void UnBind();
	bool IsBound() { return m_isBound; };
private:
	unsigned int m_rendererID = 0;
	bool m_isBound = true;
};

