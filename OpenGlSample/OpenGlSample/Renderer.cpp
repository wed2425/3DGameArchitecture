#include <stdio.h>
#include "Renderer.h"



void Renderer::addRenderObject(RenderableObject* obj)
{
	_objVector.push_back(obj);
}

void Renderer::addNonRenderObject(NonRenderableObject * obj)
{
	_nonobjVector.push_back(obj);
}

void Renderer::init()
{
	

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return;
	}

	
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "Tutorial 08 - Basic Shading", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Set the mouse at the center of the screen
	
	//glfwSetCursorPos(window, 1024 / 2, 768 / 2);

	// Dark blue background
	glClearColor(0.0f, 0.7f, 0.0f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	//glEnable(GL_CULL_FACE);

	for (std::vector<RenderableObject*>::iterator it = _objVector.begin(); it != _objVector.end(); it++)
	{
		(*it)->init();
	}

	for (std::vector<NonRenderableObject*>::iterator it = _nonobjVector.begin(); it != _nonobjVector.end(); it++)
	{
		(*it)->init();
	}

}

void Renderer::Update()
{
	for (std::vector<RenderableObject*>::iterator it = _objVector.begin(); it != _objVector.end(); it++)
	{
		(*it)->Update();
	}

	for (std::vector<NonRenderableObject*>::iterator it = _nonobjVector.begin(); it != _nonobjVector.end(); it++)
	{
		(*it)->Update();

	}
}

void Renderer::render()
{
	for (std::vector<RenderableObject*>::iterator it = _objVector.begin(); it != _objVector.end(); it++)
	{
		(*it)->render();
	}

	for (std::vector<NonRenderableObject*>::iterator it = _nonobjVector.begin(); it != _nonobjVector.end(); it++)
	{
		(*it)->render();
	}
	
}



void Renderer::shutDown()
{
	for (std::vector<RenderableObject*>::iterator it = _objVector.begin(); it != _objVector.end(); it++)
	{
		(*it)->shutDown();
	}

	for (std::vector<NonRenderableObject*>::iterator it = _nonobjVector.begin(); it != _nonobjVector.end(); it++)
	{
		(*it)->shutDown();

	}

	glfwTerminate();
}



void Renderer::RenderFirst()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Renderer::RenderLast()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}



void Renderer::setPosition(float x, float y, float z)
{

}


