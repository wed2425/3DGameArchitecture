#pragma once

#include "Object.h"
#include "Renderer.h"



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

public:

	float _ObjPositionX;
	float _ObjPositionY;
	float _ObjPositionZ;
	
	


public:
	RenderableObject();
	virtual void shutDown() override {};
	virtual void setPosition(float x, float y, float z)override {};
	virtual void Update()override {};
	virtual void init()override {};
	virtual void render()override {};


};