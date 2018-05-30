#pragma once
#include "GL/glew.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

enum class Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};
// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
	
	// Camera Attributes
	// where camera is positioned in world coords
	glm::vec3 Position;
	// where camera is looking
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;
	// Euler Angles
	float Yaw;
	float Pitch;
	// Camera options
	float MovementSpeed;
	float MouseSensitivity;
	float Zoom;

	// Constructor with vectors
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
		float yaw = YAW_DEFAULT, float pitch = PITCH_DEFAULT);

	// Returns the view matrix calculated using Euler Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix();

	// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(Camera_Movement direction, float deltaTime);
	// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

	// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(float yoffset);

private:
	// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
	
	// Default camera values
	constexpr static float YAW_DEFAULT = -90.0f;
	constexpr static float PITCH_DEFAULT = 0.0f;
	constexpr static float SPEED_DEFAULT = 2.5f;
	constexpr static float SENSITIVITY_DEFAULT = 0.1f;
	constexpr static float ZOOM_DEFAULT = 45.0f;
	
	// Calculates the front vector from the Camera's (updated) Euler Angles
	void updateCameraVectors();
};
