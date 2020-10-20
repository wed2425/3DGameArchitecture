#include "Sphere.h"



Sphere::Sphere(FileManager* filepath)
{
	TextureID = glGetUniformLocation(programID, "myTextureSampler");

	filepath->loadOBj("sphere.obj", vertices, uvs, normals);

	programID = filepath->loadShaders("20161621_vs.shader", "20161621_fs.shader");

	Texture = filepath->loadDDS("uvtemplate.DDS");


	SetBuffer();


	
	
}

void Sphere::SetPosition(float x, float y, float z)
{
	_objPos_x = x;
	_objPos_y = y;
	_objPos_z = z;
}

void Sphere::SetBuffer()
{
	MatrixID = glGetUniformLocation(programID, "MVP");
	ViewMatrixID = glGetUniformLocation(programID, "V");
	ModelMatrixID = glGetUniformLocation(programID, "M");

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

}


void Sphere::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
}


