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



void RenderableObject::setMoving(bool IsCheck)
{
	IsMoveCheck = IsCheck;
}

bool RenderableObject::getMoving()
{
	return IsMoveCheck;
}





