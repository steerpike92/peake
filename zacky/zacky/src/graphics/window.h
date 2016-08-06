#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include <string>

namespace zacky {
namespace graphics {

class Window {
public:
	Window(std::string name, unsigned width, unsigned height);
	~Window();

	void update();

	GLFWwindow* getWindow();

private:
	std::string name_;
	unsigned width_, height_;

	GLFWwindow* glfw_window_;

	void initialize();
};


}// namespace graphics
}// namespace zacky
