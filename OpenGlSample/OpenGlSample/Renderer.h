#pragma once

#include "ICleanUp.h"
#include "ISetPostion.h"
#include "IUpdate.h"
#include "FileManager.h"
#include "NonRenderableObject.h"
#include "RenderableObject.h"
#include "Object.h"
#include "Renderer.h"
#include <vector>
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"



class NonRenderableObject;
class RenderableObject;




class Renderer : public ICleanUp , public ISetPosition , public IUpdate
{
private:
	
	std::vector<RenderableObject*> _objVector;
	std::vector<NonRenderableObject*> _nonobjVector;


public:
	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}



public:
	

	void RenderFirst();

	void render();

	void RenderLast();

	void addRenderObject(RenderableObject* obj);

	void addNonRenderObject(NonRenderableObject* obj);

	void init();

	GLFWwindow* window;

	
	virtual void  shutDown() override;
	virtual void Update()override;
	virtual void setPosition(float x, float y, float z)override;
	


};