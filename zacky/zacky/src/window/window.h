#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include <string>
#include <array>

#include "input.h"

struct GLFWwindow;


namespace zacky {
namespace window {



class Window {
public:
	Window(std::string name, int width, int height);
	~Window();

	void clear();
	void update();
	
	GLFWwindow* getWindow() const;
	int getWidth() const;
	int getHeight() const;

	bool isKeyPressed(int key_number) const;
	bool isKeyHeld(int key_number) const;
	bool isKeyReleased(int key_number) const;

	bool isMouseButtonPressed(int mouse_button_number) const;
	bool isMouseButtonHeld(int mouse_button_number) const;
	bool isMouseButtonReleased(int mouse_button_number) const;

	void getCursorPosition(double& x, double&y) const;

private:
	//Members
	std::string name_;
	int width_, height_;
	GLFWwindow* glfw_window_;

	//Input
	Input input_;

	//Private Methods
	void initialize();

	//FRIEND FUNCTIONS
	//================
	friend void window_resize_callback(GLFWwindow*, int, int);
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};



}// namespace window
}// namespace zacky

