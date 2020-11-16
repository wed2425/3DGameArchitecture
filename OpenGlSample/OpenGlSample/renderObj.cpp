#include "renderObj.h"
#include <iostream>

void renderObj::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(MatrixID);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void renderObj::setPosition(float x, float y, float z)
{
	_ObjPositionX = x;
	_ObjPositionY = y;
	_ObjPositionZ = z;
}

void renderObj::Update()
{
}

void renderObj::init()
{
	FileManager::instance()->loadObj(this, "sphere.obj", "ball.bmp", "20161621_vs.shader", "20161621_fs.shader");
	this->setPosition(0.9f, 0.0f, 3.0f);
}

glm::mat4 renderObj::getMatrixTranslatePosition(glm::mat4 Model, RenderableObject* obj)
{
	float a, b, c = 0;
	a = obj->_ObjPositionX;
	b = obj->_ObjPositionY;
	c = obj->_ObjPositionZ;

	Model = glm::translate(Model, glm::vec3(a, b, c));
	return Model;
}

void renderObj::render()
{
	glUseProgram(this->programID);

	InputKey::instance()->KeyBoard();
	InputKey::instance()->setMousepos();


	glm::mat4 ProjectionMatrix = InputKey::instance()->getProjectionMatrix();
	glm::mat4 ViewMatrix = InputKey::instance()->getViewMatrix();

	glm::mat4 ModelMatrix = glm::mat4(1.0);

	ModelMatrix = getMatrixTranslatePosition(ModelMatrix, this);
	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

	glUniformMatrix4fv(this->MatrixID, 1, GL_FALSE, &MVP[0][0]);
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->Texture);
	glUniform1i(this->TextureID, 0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	glBindBuffer(GL_ARRAY_BUFFER, this->uvbuffer);
	glVertexAttribPointer(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	glBindBuffer(GL_ARRAY_BUFFER, this->normalbuffer);
	glVertexAttribPointer(
		2,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	
}


