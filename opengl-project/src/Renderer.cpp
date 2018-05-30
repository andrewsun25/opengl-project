#include "stdafx.h"
#include <iostream>
#include "Renderer.h"
#include "GL/glew.h"
#include "util/Log.h"


void Renderer::clear() const
{
	GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::drawElements(VertexArray & vao, Shader & shader, unsigned int count) const
{
	vao.bind();
	GLCall(glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr));
	/*shader.unbind();
	vao.unbind();*/
}
