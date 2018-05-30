#include "stdafx.h"
#include "ResourceManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "util/Log.h"
#include "stb_image/stb_image.h"

// Public Interface
struct Resources {
	
};

ShaderProgramSource ResourceManager::ParseShaderSource(const std::string& shaderFile) const
{
	std::ifstream stream(shaderFile);
	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		// If we have found #shader
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			// Pushes the line of code into the appropriate shader's position in ss.
			ss[(int)type] << line << '\n';
		}
	}
	// return structs when you need to return multiple values.
	// could also pass in pointers to 2 and copy into them.
	// could also return new std::string[]{}; (heap allocated resource)
	// could also return a std::array (stack allocated).
	// could also return a std::vector (heap allocated).
	// tuples and pairs have horrendous syntax.
	return { ss[0].str(), ss[1].str() };
}

TextureSource ResourceManager::ParseTextureImage(const std::string& textureFile)
{
	stbi_set_flip_vertically_on_load(1);
	int width, height, bpp;
	// 4 means RGBA
	GLubyte* localBuffer = stbi_load(textureFile.c_str(), &width, &height, &bpp, 4);
	TextureSource ret = {
		localBuffer, width, height, bpp
	};
	return ret;
}





