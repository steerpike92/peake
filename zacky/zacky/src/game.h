#pragma once

#include <iostream>
#include "graphics\window.h"


namespace zacky {

class Game
{
public:
	Game();
	~Game();

private:
	graphics::Window window_;

	void loop();
};

}
