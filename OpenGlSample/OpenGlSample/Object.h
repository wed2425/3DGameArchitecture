#pragma once
#include <vector>

#include "include/GL/glew.h"
#include "glm/glm.hpp"

#include "ISetPostion.h"
#include "ICleanUp.h"
#include "IUpdate.h"
#include "IInit.h"
#include "IRender.h"

#include "include/GL/glew.h"		
#include "glm/gtc/matrix_transform.hpp"

class Object : public ICleanUp , public ISetPosition , public IUpdate , public IIinit , public IRender
{


public:
	virtual ~Object() {}
	



};