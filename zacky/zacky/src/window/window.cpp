#include "window.h"
#include "../macros.h"

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace zacky { 
namespace window {



Window::Window(std::string name, int width, int height):
	name_(name),
	width_(width),
	height_(height)
{
	initialize();
}



void Window::initialize()
{

	auto glfw_init_success = glfwInit();
	if (!glfw_init_success) {
		std::cerr << "Failed to init glfw"<<std::endl;
		LOG_ERROR;
	}


	glfw_window_ = glfwCreateWindow(width_, height_, name_.c_str(), NULL, NULL);
	if (!glfw_window_) {
		std::cerr << "Failed to create window" << std::endl;
		glfwTerminate();
		LOG_ERROR;
	}


	glfwMakeContextCurrent(glfw_window_);
	glfwSetWindowUserPointer(glfw_window_, this);
	glfwSetWindowSizeCallback(glfw_window_, window_resize_callback);
	
	auto glew_init_okay = glewInit();
	if (glew_init_okay != GLEW_OK) {
		std::cerr << "Failed to init glew" << std::endl;
		LOG_ERROR;
	}
}



void Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}



void Window::update()
{
	glfwSwapBuffers(glfw_window_);
	glfwPollEvents();
}



Window::~Window()
{
	glfwTerminate();
}



//CALLBACK DEFINITIONS
//==================================

void window_resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	Window* my_window = static_cast<Window*>(glfwGetWindowUserPointer(window));
	my_window->width_ = width;
	my_window->height_ = height;
}


}// namespace window
}// namespace zacky