#include "input.h"

#include "window.h"

namespace zacky {
namespace window {

Input::Input()
{
}

Input::Input(GLFWwindow * glfw_window)
{
	glfwSetKeyCallback(glfw_window, key_callback);

	for (auto &arr : key_arrays_)
		arr.fill(false);

	for (auto &arr : button_arrays_)
		arr.fill(false);
}

void Input::clear()
{
	key_arrays_[PRESSED].fill(false);
	key_arrays_[RELEASED].fill(false);

	button_arrays_[PRESSED].fill(false);
	button_arrays_[RELEASED].fill(false);
}


void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	Window* my_window = static_cast<Window*>(glfwGetWindowUserPointer(window));
}



}// namespace window
}// namespace zacky

