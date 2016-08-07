#pragma once
#include <iostream>
#include <string>


struct GLFWwindow;


namespace zacky {
namespace window {


class Window {
public:
	Window(std::string name, int width, int height);
	~Window();

	void clear();
	void update();
	

	inline GLFWwindow* getWindow() const;
	inline int getWidth() const;
	inline int getHeight() const;

private:
	//Members
	std::string name_;
	int width_, height_;
	GLFWwindow* glfw_window_;

	//Private Methods
	void initialize();

	//FRIEND FUNCTIONS
	//================
	friend void window_resize_callback(GLFWwindow*, int, int);
};


//INLINE WINDOW METHODS:
//======================
GLFWwindow* Window::getWindow() const { return glfw_window_; }
int Window::getWidth() const { return width_; }
int Window::getHeight() const { return height_; }


//CALLBACK DECLARATIONS
//======================
void window_resize_callback(GLFWwindow* window, int width, int height);


}// namespace window
}// namespace zacky

