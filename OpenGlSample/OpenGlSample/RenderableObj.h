#pragma once

#include "CompositeObj.h"
#include <vector>

class RenderableObj : public CompositeObj
{
private:
	bool _IsMoveCheck = false;

public:
	RenderableObj();
	virtual void init() override {};
	virtual void render() override {};
	virtual void Update() override {};
	virtual void shutDown() override {};
	virtual void setPosition(float x, float y, float z) {};
	virtual void setRotation(float speed, float x, float y, float z) {};
	virtual void setScale(float x, float y, float z) {};
	virtual void setCameraPos(float x, float y, float z) {};

	virtual void AddChild(CompositeObj* addObj)override {};

public:

	glm::vec3 Position;
	glm::vec3 cameraPos;
	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	GLuint Texture;
	GLuint TextureID;
	GLuint MatrixID;
	GLuint programID;
	GLuint VertexArrayID;
	GLuint LightID;
};

