#pragma once
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	std::string m_filepath;
	unsigned int m_rendererID;
	std::unordered_map<std::string, int> m_uniformLocationCache;
	bool m_isBound;
public:
	Shader(const std::string& filepath);
	virtual ~Shader();
	void bind();
	void unbind();
	// set uniforms
	int getUniformLocation(const std::string & name);
	void setUniform4f(const std::string & name, float v0, float v1, float v2, float v3);
	void setUniform1f(const std::string & name, float v0);
	void setUniform1i(const std::string & name, int v);
	void setUniformMat4f(const std::string & name, const glm::mat4& matrix);
private:
	ShaderProgramSource parseShader(const std::string& filepath);
	unsigned int compileShader(unsigned int type, const std::string & srcCode);
	unsigned int createShader(const std::string & vertexShader, const std::string & fragmentShader);

};

