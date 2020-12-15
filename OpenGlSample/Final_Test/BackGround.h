#pragma once
#include "RenderableObj.h"

class BackGround : public RenderableObj
{
public:
	virtual void setPosition(float x, float y, float z) override;
	virtual void setRotation(float speed, float x, float y, float z) override;
	virtual void setScale(float x, float y, float z) override;
	virtual void setCameraPos(float x, float y, float z) override;
	virtual void init() override;
	virtual void render() override;
	virtual void Update() override;
	virtual void shutDown() override;

	virtual void AddChild(CompositeObj* addObj) override;
};