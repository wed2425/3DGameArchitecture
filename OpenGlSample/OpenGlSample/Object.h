#pragma once
#include <vector>

#include "include/GL/glew.h"
#include "glm/glm.hpp"

#include "ICleanUp.h"

class Object : public ICleanUp
{


public:
	virtual ~Object() {}
};