#ifndef MYENGINE_ENTITY_H
#define MYENGINE_ENTITY_H

#include <vector>
#include <memory>
#include <typeinfo>
#include <myengine\Transform.h>

namespace myengine
{

	struct Component;
	struct Core;

	struct Entity
	{
		friend struct ::myengine::Core;

		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInitialize();

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			std::shared_ptr<T> rtn;

			for (int i = 0; i < components.size(); i++)
			{
				rtn = std::dynamic_pointer_cast<T>(components.at(i));

				if (!rtn) continue;

				return rtn;
			}

			return rtn;
		}

		void tick();
		void render();

		std::shared_ptr<Core> getCore();
		std::shared_ptr<Transform> transform;

	private:
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;

	};

}

#endif