#pragma once

#include "Object.h"

class RenderableObject : public Object
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

	glm::vec3 objpos;

	float _objPos_x;
	float _objPos_y;
	float _objPos_z;
public:
	virtual void  shutDown() override;
	virtual void SetPosition(float x, float y, float z);

};