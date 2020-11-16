#include "NonRenderableObject.h"

NonRenderableObject::NonRenderableObject()
{
	Renderer::instance()->addNonRenderObject(this);
}


void NonRenderableObject::Update()
{

}

void NonRenderableObject::setPosition(float x, float y, float z)
{
}

void NonRenderableObject::shutDown()
{
}

void NonRenderableObject::render()
{
}

void NonRenderableObject::init()
{
}
