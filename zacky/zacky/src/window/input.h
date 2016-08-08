#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <array>

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


class Input 
{
public:
	Input();
	Input(GLFWwindow *window);
	~Input() = default;

	void update();

	bool isKeyPressed(int key_number) const;
	bool isKeyHeld(int key_number) const;
	bool isKeyReleased(int key_number) const;

	bool isMouseButtonPressed(int mouse_button_number) const;
	bool isMouseButtonHeld(int mouse_button_number) const;
	bool isMouseButtonReleased(int mouse_button_number) const;

	void getCursorPosition(double& x, double& y) const;

private:

	bool checkKeyState(int key_number, KeyState state) const;
	bool checkMouseButtonState(int mouse_button_number, KeyState state) const;

	using KeyArray = std::array<bool, maxKeys()>;
	using MButtonArray = std::array<bool, maxMouseButtons()>;

	std::array<KeyArray, KEY_STATE_COUNT> key_states_;
	std::array<MButtonArray, KEY_STATE_COUNT> mouse_button_states_;

	double cursor_x_, cursor_y_;

	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};

}// namespace window
}// namespace zacky