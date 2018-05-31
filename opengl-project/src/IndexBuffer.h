#pragma once
#include <GL/glew.h>

class IndexBuffer
{
public:
	IndexBuffer(const GLuint * data, GLuint count);
	virtual ~IndexBuffer();
	void Bind();
	void UnBind();
	GLuint Count() const { return m_count; };
	bool IsBound() const { return m_isBound; };
private:
	GLuint m_rendererID;
	GLuint m_count;
	bool m_isBound;	
};

