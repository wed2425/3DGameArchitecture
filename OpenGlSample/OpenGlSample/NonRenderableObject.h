#pragma once
#include "Object.h"
#include "IUpdate.h"

class NonRenderableObject : public Object, public IUpdate
{
public:


public:
	virtual void  shutDown() override;

	virtual void Update() override;
};