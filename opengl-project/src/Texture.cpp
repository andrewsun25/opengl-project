#include "stdafx.h"
#include "Texture.h"
#include "util/Log.h"
#include "stb_image/stb_image.h"

Texture2D::Texture2D(GLubyte* data, GLuint width, GLuint height, GLuint bpp)
	: m_rendererID(0), m_localBuffer(data), m_width(width), m_height(height), m_bpp(bpp)
{
	GLCall(glGenTextures(1, &m_rendererID));
	Bind(0);
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));
	if (m_localBuffer) {
		stbi_image_free(m_localBuffer);
	}
}

Texture2D::~Texture2D()
{
	GLCall(glDeleteTextures(1, &m_rendererID));
}

void Texture2D::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));
}


