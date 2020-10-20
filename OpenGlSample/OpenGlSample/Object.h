#pragma once
#include <vector>

#include "include/GL/glew.h"
#include "glm/glm.hpp"

#include "ICleanUp.h"


#include "include/GL/glew.h"		
#include "glm/gtc/matrix_transform.hpp"

class Object : public ICleanUp
{

	glm::mat4 translate;
public:
	Object();
	virtual ~Object() {}
	



};