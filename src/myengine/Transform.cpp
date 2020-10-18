#include "Transform.h"
#include "Core.h"

#include <iostream>

namespace myengine
{
	void Transform::onInitialize()
	{
		position = rend::vec2(0.0f, 0.0f);
	}
}