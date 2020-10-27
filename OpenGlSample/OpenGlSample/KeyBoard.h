#pragma once

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Renderer.h"



class KeyBoard
{
public:
	static KeyBoard* instance()
	{
		static KeyBoard instance;

		return &instance;
	}

public:
	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;
	glm::mat4 getViewMatrix() {
		return ViewMatrix;
	}
	glm::mat4 getProjectionMatrix() {
		return ProjectionMatrix;
	}
	float speed = 3.0f;
	glm::vec3 position = glm::vec3(0, 0, 5);
	float initialFoV = 45.0f;
	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
	void Move();

	


};