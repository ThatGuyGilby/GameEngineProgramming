#ifndef MYENGINE_TRANSFORM_H
#define MYENGINE_TRANSFORM_H

#include "Component.h"

#include <rend/rend.h>

namespace myengine
{

	struct Transform : public Component
	{
		void onInitialize();
		rend::vec2 position;

	private:

	};

}

#endif