#include <myengine/myengine.h>

#include <iostream>

#define shared std::shared_ptr

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> player = core->addEntity();
	std::shared_ptr<Transform> transform = player->addComponent<Transform>();
	std::shared_ptr<Renderer> renderer = player->addComponent<Renderer>();
	std::shared_ptr<KeyboardController> keyboardController = player->addComponent<KeyboardController>();

	core->start();

	return 0;
}