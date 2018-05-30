#pragma once
#include <string>
#include "GL/glew.h"

class Texture2D
{

public:
	Texture2D(GLubyte*data, GLuint width, GLuint height, GLuint bpp);
	virtual ~Texture2D();
	void Bind(GLuint slot = 0) const;
private:
	GLuint m_rendererID;
	GLubyte* m_localBuffer;
	GLuint m_width, m_height, m_bpp; // bits per pixl
};

