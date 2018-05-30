#include "ShapeGenerator.h"
#include "glm/glm.hpp"
#include "../util/util.h"

ShapeData ShapeGenerator::makeTriangle()
{
	
	//Vertex vertices[] = {
	//	// back face
	//	glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f),
	//	glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec2(1.0f, 0.0f),
	//	glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec2(1.0f, 1.0f),
	//	glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec2(1.0f, 1.0f),
	//	glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
	//	glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f),

	//	// front face	
	//	glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f),
	//	glm::vec3(0.5f, -0.5f,  0.5f) , glm::vec2(1.0f, 0.0f),
	//	glm::vec3(0.5f,  0.5f,  0.5f) , glm::vec2(1.0f, 1.0f),
	//	glm::vec3(0.5f,  0.5f,  0.5f) , glm::vec2(1.0f, 1.0f),
	//	glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(0.0f, 1.0f),
	//	glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f),
	//	// left			 			  
	//	glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec2(1.0f, 0.0f),
	//	glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec2(1.0f, 1.0f),
	//	glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec2(0.0f, 1.0f),
	//	glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec2(0.0f, 1.0f),
	//	glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec2(0.0f, 0.0f),
	//	glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec2(1.0f, 0.0f),
	//	// right			 
	//	glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f),
	//	glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f),
	//	glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
	//	glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
	//	glm::vec3(0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f),
	//	glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f),
	//	// bottom			 
	//	glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
	//	glm::vec3(0.5f, -0.5f, -0.5f) , glm::vec2(1.0f, 1.0f),
	//	glm::vec3(0.5f, -0.5f,  0.5f) , glm::vec2(1.0f, 0.0f),
	//	glm::vec3(0.5f, -0.5f,  0.5f) , glm::vec2(1.0f, 0.0f),
	//	glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f),
	//	glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
	//	// top			 
	//	glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
	//	glm::vec3(0.5f,  0.5f, -0.5f) , glm::vec2(1.0f, 1.0f),
	//	glm::vec3(0.5f,  0.5f,  0.5f) , glm::vec2(1.0f, 0.0f),
	//	glm::vec3(0.5f,  0.5f,  0.5f) , glm::vec2(1.0f, 0.0f),
	//	glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(0.0f, 0.0f),
	//	glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f)
	//};

	
	
	ShapeData ret;
	ret.countVertices = NUM_ARRAY_ELEMENTS(vertices);
	ret.countIndices = NUM_ARRAY_ELEMENTS(indices);
	ret.vertices = new Vertex[ret.countVertices];
	ret.indices = new unsigned int[ret.countIndices];
	// dst, src, sizeof(src). Copies src to dst
	memcpy(ret.vertices, vertices, sizeof(vertices));
	memcpy(ret.indices, indices, sizeof(indices));
	return ret;
}
