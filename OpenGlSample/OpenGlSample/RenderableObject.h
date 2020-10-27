#pragma once

#include "Object.h"

#include "Renderer.h"
#include "IRender.h"


class RenderableObject : public Object , public IRender
{
private:
	bool IsMoveCheck = false;
public:
	

	glm::vec3 Position;
	glm::vec3 Scale;
	
	


public:

	virtual void  shutDown() override;
	virtual void SetPosition(float x, float y, float z) {};
	virtual void setMoving(bool IsCheck);
	virtual bool getMoving();
	virtual void SetScale(float x,float y,float z) {};


};