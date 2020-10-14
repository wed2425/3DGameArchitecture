#include "Sphere.h"



Sphere::Sphere()
{
	/*
	VertexArrayID = _VertexID;
	programID = _programID;
	MatrixID = _MatrixID;
	ViewMatrixID = _ViewMatrixID;
	ModelMatrixID =_ModelMatrixID;
	Texture = _Texture;
	TextureID = _TextureID;
	vertices = _vertices;
	uvs = _uvs;
	normals = _normals;
	vertexbuffer = _vertexbuffer;
	uvbuffer = _uvbuffer;
	normalbuffer = _normalbuffer;
	LightID = _LightID;
	*/
	

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

void Sphere::drawSphere()
{
	file->loadObj(
		this,
		"sphere.obj",
		"uvtemplate.DDS",
		"20161621_vs.shader",
		"20161621_fs.shader"

	);
	
}
