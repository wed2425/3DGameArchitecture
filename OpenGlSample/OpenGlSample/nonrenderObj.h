#pragma once
#include "NonRenderableObject.h"

class nonrenderObj : public NonRenderableObject
{
public:
	virtual void Update()override;
	virtual void setPosition(float x, float y, float z) override;
	virtual void shutDown()override;
	virtual void render()override;
	virtual void init() override;
};