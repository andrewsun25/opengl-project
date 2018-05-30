#pragma once
#include <vector>
#include <GL/glew.h>

struct VertexBufferAttribute
{
	int count; // number of components that a single attribute has.
	unsigned int type; // all GL_ENUMS are unsigned ints
	unsigned char normalized; // GL_BOOLEAN
	int size; // total raw number of bytes that an entire attribute takes up.
	VertexBufferAttribute(int count, unsigned int type, unsigned char normalized)
		:count(count), type(type), normalized(normalized)
	{
		switch (type)
		{
			case GL_FLOAT: size = count * sizeof(GLfloat); break;
			case GL_UNSIGNED_INT: size = count * sizeof(GLuint); break;
			case GL_UNSIGNED_BYTE: size = count * sizeof(GLubyte); break;
			default: _ASSERT(false); break;
		}
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferAttribute> m_elements;
	unsigned int m_stride;
public:
	VertexBufferLayout()
		:m_stride(0) {}

	virtual ~VertexBufferLayout() {};

	template<typename T>
	void push(int count)
	{
		// this code should never run.
		static_assert(false);
	}

	template<>
	void push<float>(int count)
	{
		m_elements.emplace_back(count, GL_FLOAT, GL_FALSE);
		m_stride += count * sizeof(GLfloat); // size of an entire attribute.
	};

	template<>
	void push<unsigned int>(int count)
	{
		m_elements.emplace_back(count, GL_UNSIGNED_INT, GL_FALSE);
		m_stride += count * sizeof(GLuint);
	};

	template<>
	void push<unsigned char>(int count)
	{
		m_elements.emplace_back(count, GL_UNSIGNED_BYTE, GL_TRUE);
		m_stride += count * sizeof(GLubyte);
	};

	inline const std::vector<VertexBufferAttribute>& getAttrs() const { return m_elements; };
	inline unsigned int getStride() const { return m_stride; };
};

