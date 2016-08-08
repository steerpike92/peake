#pragma once
#include <iostream>
#include <string>
#include <array>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

struct GLFWwindow;


namespace zacky {
namespace window {


enum KeyState {
	PRESSED,
	HELD,
	RELEASED,
	KEY_STATE_COUNT
};


inline constexpr size_t maxKeys() { return GLFW_KEY_LAST; }
inline constexpr size_t maxMouseButtons() { return GLFW_MOUSE_BUTTON_LAST; }

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


	using KeyArray = std::array<bool, maxKeys()>;
	using MButtonArray = std::array<bool, maxMouseButtons()>;

	//Input
	std::array<KeyArray, KEY_STATE_COUNT> key_states_;
	std::array<MButtonArray, KEY_STATE_COUNT> mouse_button_states_;

	double cursor_x_, cursor_y_;

	//Private Methods
	void initialize();
	void clearInput();

	//FRIEND FUNCTIONS
	//================
	friend void window_resize_callback(GLFWwindow*, int, int);
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};


//INLINE WINDOW METHODS:
//======================
GLFWwindow* Window::getWindow() const { return glfw_window_; }
int Window::getWidth() const { return width_; }
int Window::getHeight() const { return height_; }



}// namespace window
}// namespace zacky

