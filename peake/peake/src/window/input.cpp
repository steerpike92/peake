#include "input.h"
#include "window.h"

namespace peake {
namespace window {


Input::Input()
{
}



Input::Input(GLFWwindow* window):
	cursor_x_(0.0),
	cursor_y_(0.0)
{
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	update();
}



bool Input::checkKeyState(int key_number, KeyState state) const
{
	if (key_number <= GLFW_KEY_LAST && state < KEY_STATE_COUNT)
		return key_states_[state][key_number];
	else
		return false;
}



bool Input::checkMouseButtonState(int mouse_button_number, KeyState state) const
{
	if (mouse_button_number <= GLFW_MOUSE_BUTTON_LAST && state < KEY_STATE_COUNT)
		return mouse_button_states_[state][mouse_button_number];
	else
		return false;
}



bool Input::isKeyPressed(int key_number) const {return checkKeyState(key_number, PRESSED);}
bool Input::isKeyHeld(int key_number) const { return checkKeyState(key_number, HELD);}
bool Input::isKeyReleased(int key_number) const  { return checkKeyState(key_number, RELEASED); }

bool Input::isMouseButtonPressed(int mouse_button_number) const { return checkMouseButtonState(mouse_button_number, PRESSED); }
bool Input::isMouseButtonHeld(int mouse_button_number) const { return checkMouseButtonState(mouse_button_number, HELD); }
bool Input::isMouseButtonReleased(int mouse_button_number) const { return checkMouseButtonState(mouse_button_number, RELEASED); }

void Input::getCursorPosition(double& x, double& y) const
{
	x = cursor_x_;
	y = cursor_y_;
}



void Input::update()
{
	key_states_[PRESSED].fill(false);
	key_states_[RELEASED].fill(false);

	mouse_button_states_[PRESSED].fill(false);
	mouse_button_states_[RELEASED].fill(false);

	glfwPollEvents();
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* my_window = static_cast<Window*>(glfwGetWindowUserPointer(window));
	Input* input = &my_window->input_;

	switch (action) {
	case(GLFW_PRESS):
		input->key_states_[PRESSED][key] = true;
		input->key_states_[HELD][key] = true;
		break;
	case(GLFW_REPEAT):
		//currently irrelevant
		//my_window->key_states_[HELD][key] = true;
		break;
	case(GLFW_RELEASE):
		input->key_states_[RELEASED][key] = true;
		input->key_states_[HELD][key] = false;
		break;
	default:
		std::cout << "why here of all places?" << std::endl;
	}

}



void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window* my_window = static_cast<Window*>(glfwGetWindowUserPointer(window));
	Input* input = &my_window->input_;

	switch (action) {
	case(GLFW_PRESS):
		input->mouse_button_states_[PRESSED][button] = true;
		input->mouse_button_states_[HELD][button] = true;
		break;
	case(GLFW_REPEAT): break;
		//currently irrelevant
		//my_window->key_states_[HELD][key] = true;
	case(GLFW_RELEASE): break;
		input->mouse_button_states_[RELEASED][button] = true;
		input->mouse_button_states_[HELD][button] = false;
	}
}



void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window* my_window = static_cast<Window*>(glfwGetWindowUserPointer(window));
	Input* input = &my_window->input_;

	input->cursor_x_ = xpos;
	input->cursor_y_ = ypos;

}



}// namespace window
}// namespace peake