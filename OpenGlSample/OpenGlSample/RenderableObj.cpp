#include "RenderableObj.h"
#include "Renderer.h"

RenderableObj::RenderableObj()
{
	//_IsMoveCheck = false;
	Renderer* renderer = Renderer::instance();
	renderer->addRenderObj(this);
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotVec = glm::vec3(0.0f, 0.0f, 0.0f);
	scaleVec = glm::vec3(0.0f, 0.0f, 0.0f);
	Rot = glm::mat4(1.0f);
	Scale = glm::mat4(1.0f);
	rotSpeed = 0.0f;
}
