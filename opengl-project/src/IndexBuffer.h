#pragma once
#include <GL/glew.h>

class IndexBuffer
{
public:
	IndexBuffer(const GLuint * data, GLuint count);
	void Bind();
	void UnBind();
	GLuint Count() const { return m_count; };
	bool IsBound() const { return m_isBound; };
private:
	GLuint m_rendererID = 0;
	GLuint m_count = 0;
	bool m_isBound = true;	
};

