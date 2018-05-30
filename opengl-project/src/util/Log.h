#pragma once
#include <iostream>
#include "GL/glew.h"
#include <string>

namespace {
	void LogErrorCall(const std::string & message, const char * file, int line) 
	{
		std::cout << "[ERROR]: " << message << " at " << file << ":" << line << std::endl;
	}
	#define LOG_ERROR(x) LogErrorCall(x, __FILE__, __LINE__)
	// If we call ASSERT(false), our program will exit in debug mode.
	void GLClearError() 
	{
		/* clears all errors */
		while (glGetError() != GL_NO_ERROR);
	}

	bool GLLogCall(const char* function, const char * file, int line)
	{
		bool noErrors = true;
		GLenum errorCode;
		while ((errorCode = glGetError()) != GL_NO_ERROR)
		{
			noErrors = false;
			std::string error;
			switch (errorCode)
			{
			case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
			case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
			case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
			case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
			case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
			case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
			case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
			}
			std::cout << error << " at " << function << " " << file << ":" << line << std::endl;
		}
		return noErrors;
	}
	#define ASSERT(x) if (!(x)) __debugbreak();
	#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))
}
