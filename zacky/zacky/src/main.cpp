#include <iostream>
#include <fstream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "game.h"



void error_callback(int error, const char* description)
{
	std::cerr << "Error: " << description << std::endl;
}



int main(int argc, char* args[])
{
	//redirect cerr to "error-log.txt"
	std::ofstream err("../error-log.txt");
	std::cerr.rdbuf(err.rdbuf());

	glfwSetErrorCallback(error_callback);

	//Game loop entered through constructor
	zacky::Game game;

	return 0;
}

