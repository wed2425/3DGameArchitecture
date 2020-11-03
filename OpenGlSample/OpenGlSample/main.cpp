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
#include "Sphere.h"
#include "Human.h"

int main()
{
	FileManager* file_mgr = FileManager::instance();


	Renderer::instance()->init();

	NonRenderableObject* nonobj = new NonRenderableObject();

	RenderableObject* cube = new RenderableObject();

	Sphere* sphere = new Sphere(file_mgr);
	
	Human* human = new Human(file_mgr);
	
	
	file_mgr->loadObj(
		cube,
		"ground.obj",
		"background.bmp",
		"20161621_vs.shader",
		"20161621_fs.shader"
		);
	
	cube->SetPosition(1.0f, 0.0f, 0.0f);
	
	sphere->SetPosition(1.5f, 2.0f, 2.0f);

	human->SetPosition(0.9f, 0.0f, 3.0f);

	sphere->setMoving(true);

	Renderer::instance()->addObject(cube);
	Renderer::instance()->addObject(sphere);
	Renderer::instance()->addObject(human);

	while (true)
	{
	
		
		Renderer::instance()->RenderFirst();
		if (Time::instance()->IsFixedRendering())
		{
			Renderer::instance()->Update(nonobj);
		}
		
		Renderer::instance()->RenderObject();
		Renderer::instance()->RenderLast();
		Renderer::instance()->Quit();
		
	
	}
	cube->shutDown();
	sphere->shutDown();
	Renderer::instance()->shutDown();
	
	delete cube;
	delete sphere;

	return 0;
}