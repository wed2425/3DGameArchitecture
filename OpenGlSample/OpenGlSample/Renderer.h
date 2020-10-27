#pragma once
#include "ICleanUp.h"
#include "KeyBoard.h"
#include <vector>
#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 


struct GLFWwindow;
class NonRenderableObject;
class RenderableObject;
class IUpdate;



class Renderer : public ICleanUp 
{
private:
	GLFWwindow* window;
	std::vector<RenderableObject*> _objVector;
	RenderableObject* renderobj;
	glm::vec3 cameraPos;
	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;

public:
	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}



public:
	void render(RenderableObject* src_obj);

	void RenderObject();

	void init();

	void addObject(RenderableObject* _Obj);

	virtual void  shutDown() override;

	GLFWwindow* GetWindow() const { return window; }

	glm::mat4 GetPosition(glm::mat4 , RenderableObject* src_obj);

	void RenderFirst();

	void RenderLast();

	void Update(IUpdate* _src_obj);

	void Quit();

	glm::mat4 ModelMatrix;

	float initialFov = 45.0f;

};