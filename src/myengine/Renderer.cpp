#include "Renderer.h"
#include "Core.h"
#include "Transform.h"
#include "Entity.h"
#include <iostream>

namespace myengine
{

	void Renderer::onInitialize()
	{
		/// <summary>
		/// Requirements
		/// </summary>
		if (getEntity()->getComponent<Transform>() == NULL) getEntity()->addComponent<Transform>();
		
		std::cout << "Initializing" << std::endl;

		const char* src =
		"\n#ifdef VERTEX\n                       " \
		"attribute vec2 a_Position;              " \
		"                                        " \
		"void main()                             " \
		"{                                       " \
		"  gl_Position = vec4(a_Position, 0, 1); " \
		"}                                       " \
		"                                        " \
		"\n#endif\n                              " \
		"\n#ifdef FRAGMENT\n                     " \
		"                                        " \
		"void main()                             " \
		"{                                       " \
		"  gl_FragColor = vec4(1, 0, 0, 1);      " \
		"}                                       " \
		"                                        " \
		"\n#endif\n                              ";

		shader = getCore()->context->createShader();
		shader->parse(src);

		shape = getCore()->context->createBuffer();

		rend::vec2 worldPosition = getEntity()->transform->position;

		shape->add(worldPosition + rend::vec2(0, 0.125f));
		shape->add(worldPosition + rend::vec2(-0.125f, -0.125f));
		shape->add(worldPosition + rend::vec2(0.125f, -0.125f));
	}

	void Renderer::onRender()
	{
		shape = getCore()->context->createBuffer();

		rend::vec2 worldPosition = getEntity()->transform->position;

		shape->add(worldPosition + rend::vec2(0, 0.125f));
		shape->add(worldPosition + rend::vec2(-0.125f, -0.125f));
		shape->add(worldPosition + rend::vec2(0.125f, -0.125f));

		shader->setAttribute("a_Position", shape);
		shader->render();
	}

}

