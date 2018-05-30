#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include <glm/glm.hpp>

class Renderer 
{
public:
	void clear() const;
	void drawElements(VertexArray& va, Shader& shader, unsigned int count) const;
};