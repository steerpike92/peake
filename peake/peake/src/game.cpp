#include "game.h"
#include <iostream>
#include "macros.h"

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <Eigen\Dense>


namespace peake {



Game::Game():
	window_("Zacky Window",960, 540)
{
	std::string s = glfwGetVersionString();
	std::cout << s << std::endl;

	loop();
}



Game::~Game()
{
}





void Game::loop()
{
	glClearColor(0.2f, 0.1f, 0.8f, 1.0f);

	while (!glfwWindowShouldClose(window_.getWindow())) {
		window_.clear();
		
		window_.update();
	}
}



}//namespace peake
