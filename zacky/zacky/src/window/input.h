#pragma once

#include <GLFW\glfw3.h>

#include <array>


namespace zacky {
namespace window {


inline constexpr size_t maxKeys() { return GLFW_KEY_LAST; }
inline constexpr size_t maxButtons() { return GLFW_MOUSE_BUTTON_LAST; }


enum InputState{
	PRESSED,
	HELD,
	REPEATED,
	RELEASED,
	INPUT_STATE_COUNT
};


class Input {
public:
	Input();
	Input(GLFWwindow* glfw_window);
	~Input() = default;

	void clear();
	void update();



private:

	using KeyArray = std::array<bool, maxKeys()>;
	using ButtonArray = std::array<bool, maxButtons()>;

	std::array<KeyArray, INPUT_STATE_COUNT> key_arrays_;
	std::array<ButtonArray, INPUT_STATE_COUNT> button_arrays_;

	double mouse_x_, mouse_y_;

	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


}// namespace window
}// namespace zacky
