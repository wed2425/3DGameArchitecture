#pragma once
#include "RenderableObject.h"
#include "FileManager.h"

class Sphere : public RenderableObject
{
private:
	FileManager* file;
public:
	Sphere();
	virtual void shutDown() override;
	void drawSphere();
public:
	GLuint _VertexID;
	GLuint _programID;
	GLuint _MatrixID;
	GLuint _ViewMatrixID;
	GLuint _ModelMatrixID;
	GLuint _Texture;
	GLuint _TextureID;
	std::vector<glm::vec3> _vertices;
	std::vector<glm::vec2> _uvs;
	std::vector<glm::vec3> _normals;
	GLuint _vertexbuffer;
	GLuint _uvbuffer;
	GLuint _normalbuffer;
	GLuint _LightID;
};

