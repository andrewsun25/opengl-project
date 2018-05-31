#pragma once

#include <map>
#include <string>

#include <GL/glew.h>

#include "texture.h"
#include "shader.h"


// A static singleton ResourceManager class that hosts several
// functions to load Textures and Shaders. Each loaded texture
// and/or shader is also stored for future reference by string
// handles. All functions and resources are static and no 
// public constructor is defined.
class ResourceManager
{
public:
	ResourceManager() = delete;
	// Resource storage
	static std::map<std::string, Shader>    Shaders;
	static std::map<std::string, Texture> Textures;
	// Loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
	static Shader   LoadShader(const std::string& file, const std::string& name);
	// Retrieves a stored sader
	static Shader   GetShader(const std::string& name);
	// Loads (and generates) a texture from file
	static Texture LoadTexture(const std::string&file, std::string name);
	// Retrieves a stored texture
	static Texture GetTexture(const std::string& name);
	// Properly de-allocates all loaded resources
	static void      Clear();
private:
};

