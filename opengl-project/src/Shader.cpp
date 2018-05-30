#include "GL/glew.h"
#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Renderer.h"
#include "util/Log.h"

Shader::Shader(const std::string & filepath)
	:m_filepath(filepath), m_isBound(false)
{
	ShaderProgramSource source = parseShader(filepath);
	m_rendererID = createShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(m_rendererID));
}

void Shader::bind()
{
	m_isBound = true;
	GLCall(glUseProgram(m_rendererID));
}

void Shader::unbind()
{
	m_isBound = false;
	GLCall(glUseProgram(0));
}

int Shader::getUniformLocation(const std::string & name)
{
	// if the uniform is already in the cache, return its location
	if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end()) {
		return m_uniformLocationCache[name];
	}
	// glGetUniformLocation doesn't require glUseProgram
	GLCall(int uniformLocation = glGetUniformLocation(m_rendererID, name.c_str()));
	if (uniformLocation == -1) {
		std::cout << "uniform: " << name << " not found" << std::endl;
	}
	// cache the location of the uniform
	m_uniformLocationCache[name] = uniformLocation;
	return uniformLocation;
}

void Shader::setUniform4f(const std::string & name, float v0, float v1, float v2, float v3)
{
	// glUniform4f DOES require glUseProgram to be called first
	ASSERT(m_isBound);
	GLCall(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
}

void Shader::setUniform1f(const std::string & name, float v0)
{
	ASSERT(m_isBound);
	GLCall(glUniform1f(getUniformLocation(name), v0));
}

void Shader::setUniform1i(const std::string & name, int v)
{
	GLCall(glUniform1i(getUniformLocation(name), v));
}

void Shader::setUniformMat4f(const std::string & name, const glm::mat4 & matrix)
{
	// modify a uniform that is 1 matrix, not normalized, beginning @ first element of param. 
	GLCall(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}
// private file parsing code
ShaderProgramSource Shader::parseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);
	// use enum class over enums
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

unsigned int Shader::compileShader(unsigned int type, const std::string & srcCode)
{
	// id is the final shader to be returned
	unsigned int id = glCreateShader(type);
	const char* src = srcCode.c_str();
	// Replaces source code in id's shader obj with src. nullptr for lengths array.
	GLCall(glShaderSource(id, 1, &src, nullptr));
	// Compiles the shader
	GLCall(glCompileShader(id));
	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	// invalid
	if (result == GL_FALSE)
	{
		int length;
		GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		char * message = (char*)alloca(length * sizeof(char));
		GLCall(glGetShaderInfoLog(id, length, &length, message));
		std::cout << "Failed to compile" <<
			(type == GL_VERTEX_SHADER ? "vertex" : "fragment")
			<< " shader" << std::endl;
		std::cout << message << std::endl;
		GLCall(glDeleteShader(id));
		return 0;
	}
	return id;
}

unsigned int Shader::createShader(const std::string & vertexShader, const std::string & fragmentShader)
{
	// create a glProgram
	GLCall(unsigned int program = glCreateProgram()); // GLuint is equivalent to unsigned int.
											  // create a glShader using the provided src code.
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
	// Attach, Link, Validate, delete linked shaders.
	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));
	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));
	return program;
}


