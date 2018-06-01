#pragma once
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>
#include "util/Log.h"
#include "OGLGarbageCollected.h"

class Shader : OGLGarbageCollected
{
public:
	Shader() = default; // calls OGLGarbageCollected() and generates a shared_ptr
	Shader(const std::string& filepath); // calls OGLGarbageCollected() and generates a shared_ptr
	// Implicit Copy Cnstructor calls OGLGarbageCollected implicit copy constructor.
	// Implicit Copy Assignment calls OGLGarbageCollected implicit copy assignment operator.
	~Shader() {
		DeleteResourceIfLone();
	}
	void Bind();
	void UnBind();
	// Inherits bool IsBound() from OGLGarbageCollected
	
	// set uniforms
	int GetUniformLocation(const std::string & name);
	void SetUniform4f(const std::string & name, float v0, float v1, float v2, float v3);
	void SetUniform1f(const std::string & name, float v0);
	void SetUniform1i(const std::string & name, int v);
	void SetUniformMat4f(const std::string & name, const glm::mat4& matrix);
private:
	std::unordered_map<std::string, int> m_uniformLocationCache = std::unordered_map<std::string, int>();
	
	void DeleteResourceIfLone();
	
	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CreateShader(const std::string & vertexShader, const std::string & fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string & srcCode);
};

