#pragma once
#include "Vertex.h"

struct ShapeData
{
	Vertex* vertices;
	unsigned int countVertices;
	unsigned int* indices;
	unsigned int countIndices;
};

class ShapeGenerator
{
public:
	static ShapeData makeTriangle();
};

