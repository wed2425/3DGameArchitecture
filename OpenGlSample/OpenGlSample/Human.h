#pragma once
#include "RenderableObject.h"
#include "FileManager.h"



class Human : public RenderableObject
{
private:


public:
	Human(FileManager* filepath);
	virtual void shutDown() override;

	virtual void SetPosition(float x, float y, float z) override;
	void SetBuffer();


private:





};

