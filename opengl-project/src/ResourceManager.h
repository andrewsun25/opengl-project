#pragma once

#include <map>
#include <string>
#include <GL/glew.h>
#include "texture.h"
#include "shader.h"
#include <memory>

// POD struct for storing parsed vertex and frag shader
struct ShaderProgramSource
{
	std::string vertexSource;
	std::string fragmentSource;
};

struct TextureSource
{
	GLubyte* data;
	GLuint width, height, bpp;
};
// Singleton class responsible for parsing shaders and textures
class ResourceManager
{
public:
	// Public Interface
	
	// Loads shader file and returns vertex/fragment shader files seperately
	ShaderProgramSource ParseShaderSource(const std::string& shaderFile) const;
	TextureSource ParseTextureImage(const std::string& textureFile);
	// no matter how many times we call getInstance(), we will always get a reference to the same RM obj
	static ResourceManager& getInstance()
	{
		// instance is initialized only once. 
		static ResourceManager instance; 
		return instance;
	}
	// disallow assignment and copy construction for singleton class
	ResourceManager(ResourceManager const&) = delete;
	void operator=(ResourceManager const&) = delete;
private:
	
	// Private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
	ResourceManager(){ }
	
};
