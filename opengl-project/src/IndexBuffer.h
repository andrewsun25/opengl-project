#pragma once

class IndexBuffer
{
private:
	// renderer is generic name that is cross API
	unsigned int m_rendererID;
	unsigned int m_count;
	// move m_isBound back
	friend class VertexArray;
public:
	bool m_isBound;
	IndexBuffer(const unsigned int * data, unsigned int count);
	virtual ~IndexBuffer();
	void bind();
	void unbind();
	unsigned int getCount() const { return m_count; }
};

