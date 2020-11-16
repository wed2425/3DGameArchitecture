#pragma once
#include "RenderableObject.h"
#include "FileManager.h"



class Sphere : public RenderableObject 
{
private:


public:
	Sphere(FileManager * filepath);
	virtual void shutDown() override;

	void SetBuffer();


private:




	
};

