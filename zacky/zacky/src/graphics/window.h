#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include <string>

namespace zacky {
namespace graphics {

class Window {
public:
	Window(std::string name, int width, int height);
	~Window();

	void clear() const;
	void update();
	

	inline GLFWwindow* getWindow() const;
	inline int getWidth() const;
	inline int getHeight() const;

private:
	std::string name_;
	static int width_, height_;
	GLFWwindow* glfw_window_;

	void initialize();

	friend void WindowResize(GLFWwindow*, int, int);
};


//INLINE WINDOW METHODS:
//======================

GLFWwindow* Window::getWindow() const { return glfw_window_; }
inline int Window::getWidth() const { return width_; }
inline int Window::getHeight() const { return height_; }




}// namespace graphics
}// namespace zacky

