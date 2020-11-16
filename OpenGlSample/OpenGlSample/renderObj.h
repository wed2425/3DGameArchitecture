#pragma once
#include "RenderableObject.h"
#include "FileManager.h"
#include "InputKey.h"

class renderObj : public RenderableObject
{
public:
	virtual void shutDown() override;
	virtual void setPosition(float x, float y, float z)override;
	virtual void Update() override;
	virtual void init() override;
	virtual void render() override;
	glm::mat4 getMatrixTranslatePosition(glm::mat4 Model, RenderableObject* obj);
};