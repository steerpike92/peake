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
	
	input_ = Input(glfw_window_);

	auto glew_init_okay = glewInit();
	if (glew_init_okay != GLEW_OK) {
		std::cerr << "Failed to init glew" << std::endl;
		LOG_ERROR;
	}

	glfwSwapInterval(1);
}



void Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}



void Window::update()
{
	glfwSwapBuffers(glfw_window_);
	input_.update();

	if (isKeyPressed(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(glfw_window_, GLFW_TRUE);
}



GLFWwindow* Window::getWindow() const { return glfw_window_; }
int Window::getWidth() const { return width_; }
int Window::getHeight() const { return height_; }

bool Window::isKeyPressed(int key_number) const { return input_.isKeyPressed(key_number); }
bool Window::isKeyHeld(int key_number) const { return input_.isKeyHeld(key_number);}
bool Window::isKeyReleased(int key_number) const { return input_.isKeyReleased(key_number);}
     
bool Window::isMouseButtonPressed(int mouse_button_number) const { return input_.isMouseButtonPressed(mouse_button_number); }
bool Window::isMouseButtonHeld(int mouse_button_number) const { return input_.isMouseButtonHeld(mouse_button_number);}
bool Window::isMouseButtonReleased(int mouse_button_number) const { return input_.isMouseButtonReleased(mouse_button_number);}

void Window::getCursorPosition(double& x, double&y) const 
{
	input_.getCursorPosition(x, y);
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