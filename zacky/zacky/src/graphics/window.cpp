#include "window.h"
#include "../macros.h"

namespace zacky { 
namespace graphics {



int Window::height_{ 0 };
int Window::width_{ 0 };



Window::Window(std::string name, int width, int height):
	name_(name)
{
	width_ = width;
	height_ = height;
	initialize();
}




//free function declaration
void WindowResize(GLFWwindow* window, int width, int height);


void Window::initialize()
{

	auto glfw_init_success = glfwInit();
	if (!glfw_init_success) {
		std::cout << "Failed to init glfw"<<std::endl;
		LOG_ERROR;
	}


	glfw_window_ = glfwCreateWindow(width_, height_, name_.c_str(), NULL, NULL);
	if (!glfw_window_) {
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		LOG_ERROR;
	}

	glfwMakeContextCurrent(glfw_window_);
	glfwSetWindowSizeCallback(glfw_window_, WindowResize);

	auto glew_init_okay = glewInit();
	if (glew_init_okay != GLEW_OK) {
		std::cout << "Failed to init glew" << std::endl;
		LOG_ERROR;
	}
}



void Window::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}



void Window::update()
{
	
	glfwSwapBuffers(glfw_window_);

}



Window::~Window()
{
	glfwTerminate();
}



//Free function
void WindowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	Window::width_ = width;
	Window::height_ = height;
	//std::cout << Window::width_ << ", " << Window::height_ << std::endl;
}



}// namespace graphics
}// namespace zacky