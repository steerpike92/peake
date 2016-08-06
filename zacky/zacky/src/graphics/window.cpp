#include "window.h"

namespace zacky { 
namespace graphics {

Window::Window(std::string name, unsigned width, unsigned height):
	name_(name),
	width_(width),
	height_(height)
{
	initialize();
}



Window::~Window()
{
	glfwTerminate();
}



void Window::update()
{

}



GLFWwindow* Window::getWindow()
{
	return glfw_window_;
}



void Window::initialize()
{

	if (!glewInit()) {
		std::cout << "Failed to init glew" << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	if (!glfwInit()) {
		std::cout << "Failed to init glfw" << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}


	glfw_window_ = glfwCreateWindow(width_, height_, name_.c_str() , NULL, NULL);
	if (!glfw_window_)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
}



}// namespace graphics
}// namespace zacky