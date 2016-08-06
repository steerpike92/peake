#include "game.h"
#include <iostream>

namespace zacky {



Game::Game():
	window_("Zacky Window",1600, 900)
{
	loop();
}



Game::~Game()
{
}



void Game::loop()
{
	while (!glfwWindowShouldClose(window_.getWindow())) {

		window_.update();
		glfwSwapBuffers(window_.getWindow());
		glfwPollEvents();
	}
}



}//namespace zacky


