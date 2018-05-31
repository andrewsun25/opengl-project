#pragma once
#include <string>
#include "GL/glew.h"
#include "util/Log.h"

class Texture
{
public:
	Texture() = default;
	Texture(const std::string& filepath);
	// No destructor because we want to be able to copy/assign 
	// textures without destructor deleting the texture.
	void Bind();
	void UnBind();
	bool IsBound() const { return m_isBound; };
private:
	GLuint m_rendererID = 0;
	int m_width = 0, m_height = 0, m_bpp = 0; // bits per pixl
	bool m_isBound = true;
};

