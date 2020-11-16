#pragma once
#include "RenderableObject.h"
#include "FileManager.h"



class Human : public RenderableObject
{
private:


public:
	Human(FileManager* filepath);
	virtual void shutDown() override;

	void SetBuffer();


private:





};

