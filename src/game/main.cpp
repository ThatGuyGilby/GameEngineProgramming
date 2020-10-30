#include <myengine/myengine.h>

#include <iostream>

#define shared std::shared_ptr

std::shared_ptr<Entity> createPlayer(std::shared_ptr<Core> core)
{
	std::shared_ptr<Entity> rtn = core->addEntity();
	std::shared_ptr<Transform> transform = rtn->addComponent<Transform>();
	std::shared_ptr<Renderer> renderer = rtn->addComponent<Renderer>();
	std::shared_ptr<KeyboardController> keyboardController = rtn->addComponent<KeyboardController>();

	return rtn;
}

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> player = createPlayer(core);

	player->getComponent<KeyboardController>();

	core->start();

	player->getComponent<Renderer>();

	return 0;
}