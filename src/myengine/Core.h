#ifndef MYENGINE_CORE_H
#define MYENGINE_CORE_H

#include <SDL2/SDL.h>
#include <rend/rend.h>

#include <memory>
#include <vector>

namespace myengine
{
	struct Renderer;
	struct Entity;

	struct Core
	{
		friend struct myengine::Renderer;

		static std::shared_ptr<Core> initialize();

		std::shared_ptr<Entity> addEntity();

		void start();

	private:
		std::vector<std::shared_ptr<Entity>> entities;
		std::weak_ptr<Core> self;
		SDL_Window* window;
		SDL_GLContext glContext;
		std::shared_ptr<rend::Context> context;
	};

	class Screen
	{
		int getWidth()
		{
			return width;
		}

		int getHeight()
		{
			return height;
		}

		glm::mat4 getPerspective()
		{
			return glm::perspective((float)glm::radians(90.0f), (float)(width / height), 0.1f, 100.0f);
		}

	private:
		int width;
		int height;
	};
}

#endif