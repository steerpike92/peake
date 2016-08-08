#include "window.h"
#include "../macros.h"

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace zacky { 
namespace window {



Window::Window(std::string name, int width, int height):
	name_(name),
	width_(width),
	height_(height),
	cursor_x_(0.0),
	cursor_y_(0.0)
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
	glfwSetKeyCallback(glfw_window_, key_callback);
	glfwSetMouseButtonCallback(glfw_window_, mouse_button_callback);
	glfwSetCursorPosCallback(glfw_window_, cursor_position_callback);

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



void Window::clearInput()
{
	key_states_[PRESSED].fill(false);
	key_states_[RELEASED].fill(false);

	mouse_button_states_[PRESSED].fill(false);
	mouse_button_states_[RELEASED].fill(false);
}



void Window::update()
{
	

	glfwSwapBuffers(glfw_window_);
	clearInput();
	glfwPollEvents();

	//for (int i = 0; i < key_states_[PRESSED].size(); ++i) {
	//	if (key_states_[HELD][i]) {
	//		const char* c = glfwGetKeyName(i, 0);
	//		if (c)
	//			std::cout << c << std::endl;
	//	}
	//}


	//esc quit
	if (key_states_[PRESSED][GLFW_KEY_ESCAPE])
		glfwSetWindowShouldClose(glfw_window_, 1);

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



void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* my_window = static_cast<Window*>(glfwGetWindowUserPointer(window));
	
	const char* c = glfwGetKeyName(key, scancode);
	if (c) {
		//std::cout << c << std::endl;
		//std::cout << action << std::endl;
	}

	switch (action) {
	case(GLFW_PRESS) : 
		my_window->key_states_[PRESSED][key] = true;
		my_window->key_states_[HELD][key] = true;
		break;
	case(GLFW_REPEAT) :
		//currently irrelevant
		//my_window->key_states_[HELD][key] = true;
		break;
	case(GLFW_RELEASE) :
		my_window->key_states_[RELEASED][key] = true;
		my_window->key_states_[HELD][key] = false;
		break;
	default :
		std::cout << "why here of all places?" << std::endl;
	}

}



void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window* my_window = static_cast<Window*>(glfwGetWindowUserPointer(window));
	
	switch (action) {
	case(GLFW_PRESS):
		my_window->mouse_button_states_[PRESSED][button] = true;
		my_window->mouse_button_states_[HELD][button] = true;
		break;
	case(GLFW_REPEAT): break;
		//currently irrelevant
		//my_window->key_states_[HELD][key] = true;
	case(GLFW_RELEASE): break;
		my_window->mouse_button_states_[RELEASED][button] = true;
		my_window->mouse_button_states_[HELD][button] = false;
	}
}



void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window* my_window = static_cast<Window*>(glfwGetWindowUserPointer(window));

	my_window->cursor_x_ = xpos;
	my_window->cursor_y_ = ypos;

}


}// namespace window
}// namespace zacky