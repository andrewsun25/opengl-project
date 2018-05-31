#include "stdafx.h"
#include "ResourceManager.h"
#include "util/Log.h"

std::map<std::string, Texture> ResourceManager::Textures;
std::map<std::string, Shader> ResourceManager::Shaders;

Shader ResourceManager::LoadShader(const std::string& file, const std::string& name)
{
	Shaders[name] = Shader(file);
	return Shaders[name];
}

Shader ResourceManager::GetShader(const std::string& name)
{
	return Shaders[name];
}

Texture ResourceManager::LoadTexture(const std::string & file, std::string name)
{
	Textures[name] = Texture(file);
	return Textures[name];
}

Texture ResourceManager::GetTexture(const std::string & name)
{
	return Textures[name];
}

void ResourceManager::Clear()
{
	Shaders.clear();
	Textures.clear();
}
