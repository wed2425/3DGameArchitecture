#pragma once
#include "RenderableObject.h"
#include "FileManager.h"



class Sphere : public RenderableObject 
{
private:


public:
	Sphere(FileManager * filepath);
	virtual void shutDown() override;

	virtual void SetPosition(float x, float y, float z) override;
	void SetBuffer();


private:




	
};

