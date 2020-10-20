#include "ICleanUp.h"


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

	glm::mat4 GetPosition(glm::mat4 Model, RenderableObject* _obj);

	void RenderFirst();

	void RenderLast();

	void Update(IUpdate* _src_obj);

};