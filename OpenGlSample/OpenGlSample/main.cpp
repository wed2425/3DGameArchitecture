#define _CRT_SECURE_NO_WARINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Time.h"
#include "Renderer.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "renderObj.h"
#include "nonrenderObj.h"

int main()
{
	


	FileManager::instance();
	Renderer::instance();
	renderObj* ball = new renderObj();
	nonrenderObj* nonObj = new nonrenderObj();

	Renderer::instance()->init();
	
	
	while (glfwGetKey(Renderer::instance()->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(Renderer::instance()->window) == 0)
	{
		Renderer::instance()->RenderFirst();
	
		if (Time::instance()->IsFixedRendering())
		{
			Renderer::instance()->Update();
		}
		
		Renderer::instance()->render();


		Renderer::instance()->RenderLast();
	}

	Renderer::instance()->shutDown();

	delete nonObj;
	delete ball;
	
}