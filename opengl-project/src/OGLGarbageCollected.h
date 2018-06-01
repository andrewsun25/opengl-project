#pragma once
#include <memory>
#include "GL/glew.h"
/*
	This class provides common behavior to objects which can control the openGL state machine. These objects may be copied freely, however because
	the copy will have the same m_rendererID as the original object, changes made by the copy to the openGL state should also be reflected in the original object.
	The way that this key feature will be implemented is through a shared_ptr member variable that tracks the number of identical objects exist at any point in time.
	Once an object's m_refCounter.use_count() reaches 1, that object's destructor will be responsible for deleting the openGL id.  
*/
class OGLGarbageCollected
{
public:
	OGLGarbageCollected() : m_refCounter(std::make_shared<int>(420)) {};
	// need to declare destructor as virtual default
	virtual ~OGLGarbageCollected() = default;
	
	virtual void Bind() = 0; // abstract method
	virtual void UnBind() = 0; // abstract method
	virtual bool IsBound() const { return m_isBound; };
protected:
	GLuint m_rendererID = 0;
	bool m_isBound = true;
	std::shared_ptr<int> m_refCounter;

	virtual void DeleteResourceIfLone() = 0; // abstract method
};

