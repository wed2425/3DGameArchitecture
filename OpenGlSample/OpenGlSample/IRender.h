#pragma once

#include <vector>
#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"

class IRender
{
public:

	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;
	GLuint ViewMatrixID;
	GLuint ModelMatrixID;
	GLuint Texture;
	GLuint TextureID;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint LightID;
};