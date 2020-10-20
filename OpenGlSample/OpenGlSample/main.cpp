#define _CRT_SECURE_NO_WARINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "Sphere.h"

int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();

	renderer->init();

	NonRenderableObject* nonobj = new NonRenderableObject();

	RenderableObject* cube = new RenderableObject();

	Sphere* sphere = new Sphere(file_mgr);
	
	

	file_mgr->loadObj(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"20161621_vs.shader",
		"20161621_fs.shader"
		);
	
	cube->SetPosition(1.5f, 2.0f, 2.0f);
	sphere->SetPosition(-3.0f, -1.0f, -2.0f);

	renderer->addObject(cube);
	renderer->addObject(sphere);

	while (true)
	{
	
		
		renderer->RenderFirst();
		renderer->RenderObject();
		renderer->Update(nonobj);
		renderer->RenderLast();
		
		
	
	}
	cube->shutDown();
	sphere->shutDown();
	renderer->shutDown();
	
	delete cube;
	delete sphere;

	return 0;
}