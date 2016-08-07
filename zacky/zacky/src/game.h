#pragma once

#include <iostream>
#include "window\window.h"


namespace zacky {

class Game
{
public:
	Game();
	~Game();

private:
	window::Window window_;

	void loop();
};

}
