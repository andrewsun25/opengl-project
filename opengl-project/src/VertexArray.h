#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "OGLGarbageCollected.h"

class VertexArray: OGLGarbageCollected
{
public:
	VertexArray();
	~VertexArray() {
		DeleteResourceIfLone();
	}
	void AddVertexBuffer(VertexBuffer& vb, const VertexBufferLayout& layout);
	void AddIndexBuffer(IndexBuffer& ib);
	void Bind();
	void UnBind();
	// bool IsBound() inherited
private:
	void DeleteResourceIfLone();
};

