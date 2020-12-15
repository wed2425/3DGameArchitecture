#pragma once

#include "CompositeObj.h"

class NonRenderableObj : public CompositeObj
{
public:
	NonRenderableObj();
	virtual void init() override;
	virtual void render() override;
	virtual void Update() override;
	virtual void shutDown() override;
};
