#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include <fstream>

#include "game.h"

int main(int argc, char* args[])
{
	//redirect cerr to "error-log.txt"
	std::ofstream err("../error-log.txt");
	std::cerr.rdbuf(err.rdbuf());

	//Game loop entered through constructor
	zacky::Game game;

	return 0;
}

