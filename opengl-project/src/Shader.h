#pragma once
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>
#include "util/Log.h"


class Shader
{
public:
	Shader() = default;
	Shader(const std::string& filepath);
	void Bind();
	void UnBind();
	bool IsBound() const { return m_isBound; };
	// set uniforms
	int GetUniformLocation(const std::string & name);
	void SetUniform4f(const std::string & name, float v0, float v1, float v2, float v3);
	void SetUniform1f(const std::string & name, float v0);
	void SetUniform1i(const std::string & name, int v);
	void SetUniformMat4f(const std::string & name, const glm::mat4& matrix);
private:
	unsigned int m_rendererID = 0;
	std::unordered_map<std::string, int> m_uniformLocationCache = std::unordered_map<std::string, int>();
	bool m_isBound = true;
	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CreateShader(const std::string & vertexShader, const std::string & fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string & srcCode);
};

