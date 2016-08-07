#include "game.h"
#include <iostream>
#include "macros.h"
#include <GLFW\glfw3.h>

namespace zacky {



Game::Game():
	window_("Zacky Window",960, 540)
{
	//std::string s = glfwGetVersionString();
	//std::cout << s << std::endl;
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


		glBegin(GL_TRIANGLES);
		glVertex2d(-0.5f, -0.5f);
		glVertex2d(0, 0.5f);
		glVertex2d(0.5f, -0.5f);
		glEnd();


		//GLuint vao;
		//glGenVertexArrays(1, &vao);
		//glBindVertexArray(vao);
		//glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

		window_.update();
		glfwPollEvents();
	}
}



}//namespace zacky
