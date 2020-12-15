#pragma once
#include "FileManager.h"
#include "ICleanUp.h"
#include "IUpdate.h"
#include <vector>

class RenderableObj;
class NonRenderableObj;

class Renderer : public ICleanUp
{
private:
	glm::vec3 cameraPos;

	std::vector< RenderableObj*> renderObjList;
	std::vector< NonRenderableObj*> nonrenderObjList;

public:

	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}

public:
	GLFWwindow* window;

	void addRenderObj(RenderableObj* obj);
	void addNonRenderObj(NonRenderableObj* obj);

	void render();
	int init();
	virtual void shutDown() override;

	void update();
	void Clear();
	void Out();
};
