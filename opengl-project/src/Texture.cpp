#include "stdafx.h"
#include "Texture.h"
#include "Renderer.h"
#include "stb_image/stb_image.h"
#include "util/Log.h"

Texture::Texture(const std::string & filepath)
	: m_rendererID(0), m_width(0), m_height(0), m_bpp(0), m_isBound(true)
{
	stbi_set_flip_vertically_on_load(1);
	// 4 means RGBA
	GLubyte* localBuffer = stbi_load(filepath.c_str(), &m_width, &m_height, &m_bpp, 4);
	GLCall(glGenTextures(1, &m_rendererID));
	
	Bind();

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));

	// if m_localBuffer isn't a nullptr
	if (localBuffer) {
		stbi_image_free(localBuffer);
	}
}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &m_rendererID));
}

void Texture::Bind(GLuint slot)
{
	m_isBound = true;
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));
}

void Texture::UnBind()
{
	m_isBound = false;
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
