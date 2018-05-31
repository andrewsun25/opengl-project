#pragma once
#include <string>
#include "GL/glew.h"

class Texture
{
private:
	GLuint m_rendererID;
	int m_width, m_height, m_bpp; // bits per pixl
	bool m_isBound;
public:
	Texture(const std::string& filepath);
	virtual ~Texture();
	void Bind(GLuint slot = 0);
	void UnBind();
	bool IsBound() const { return m_isBound; };
};

