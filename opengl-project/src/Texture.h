#pragma once
#include <string>
#include "GL/glew.h"
#include "util/Log.h"
#include "OGLGarbageCollected.h"

class Texture : OGLGarbageCollected
{
public:
	Texture() = default; // calls OGLGarbageCollected() and generates a new shared_ptr
	Texture(const std::string& filepath); // calls OGLGarbageCollected() and generates a new shared_ptr
	// Implicit Copy Cnstructor calls OGLGarbageCollected implicit copy constructor.
	// Implicit Copy Assignment calls OGLGarbageCollected implicit copy assignment operator.
	~Texture() {
		DeleteResourceIfLone();
	}
	void Bind();
	void UnBind();
	// bool IsBound() inherited
private:
	int m_width = 0, m_height = 0, m_bpp = 0; // bits per pixl

	void DeleteResourceIfLone();
};

