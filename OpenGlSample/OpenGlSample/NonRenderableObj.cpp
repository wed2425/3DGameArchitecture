#include "NonRenderableObj.h"
#include "Renderer.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

NonRenderableObj::NonRenderableObj()
{
	Renderer* renderer = Renderer::instance();
	renderer->addNonRenderObj(this);
}

void NonRenderableObj::init()
{

}

void NonRenderableObj::render()
{

}

void NonRenderableObj::Update()
{

}

void NonRenderableObj::shutDown()
{

}