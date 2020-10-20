#include "RenderableObject.h"

void RenderableObject::shutDown()
{
	
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);

}

void RenderableObject::SetPosition(float x, float y, float z)
{

	_objPos_x = x;
	_objPos_y = y;
	_objPos_z = z;
}



