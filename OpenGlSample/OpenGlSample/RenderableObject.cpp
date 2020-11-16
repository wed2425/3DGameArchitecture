#include "RenderableObject.h"





RenderableObject::RenderableObject()
{
	Renderer::instance()->addRenderObject(this);
}












