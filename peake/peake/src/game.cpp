#include "game.h"
#include "math\math.h"
#include "macros.h"

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <Eigen\Dense>

#include <iostream>
#include <array>

namespace peake {



Game::Game():
	window_("Zacky Window",960, 540)
{
	std::string s = glfwGetVersionString();
	std::cout << s << std::endl;


	double arr1[16]{ 1,4,6,2,4,6,7,2,3,1,1,1,0,2,5,1 };
	
	math::Matrix4d matrix1(arr1);
	math::Matrix4d matrix2(2);


	math::Matrix4d matrix3;

	matrix3 << arr1;

	double arr2[16];
	matrix2 >> arr2;

	for (int i = 0; i < 16; i++) {
		std::cout << arr2[i] << " ";
	}




	std::cout << std::endl<< matrix3 << std::endl;

		
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
