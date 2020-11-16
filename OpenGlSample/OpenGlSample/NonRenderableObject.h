#pragma once
#include "Object.h"
#include "Renderer.h"


class NonRenderableObject : public Object
{
public:
	NonRenderableObject();

public:
	virtual void Update() override;
	virtual void setPosition(float x, float y, float z)override;
	virtual void shutDown() override;
	virtual void render() override;
	virtual void init()override;
	
};