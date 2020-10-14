#include "ICleanUp.h"


struct GLFWwindow;
class Object;
class RenderableObject;


class Renderer : public ICleanUp
{
private:
	GLFWwindow* window;


public:
	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}



public:
	void render(RenderableObject* src_obj);
	void init();
	virtual void  shutDown() override;

};