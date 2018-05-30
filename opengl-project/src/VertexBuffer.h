#pragma once

class VertexBuffer
{
private:
	// renderer is generic name that is cross API
	unsigned int m_rendererID;
	// move m_isBound back
	friend class VertexArray;
public:
	bool m_isBound;
	VertexBuffer(const void * data, unsigned int size);
	virtual ~VertexBuffer();
	void bind();
	void unbind();
};

