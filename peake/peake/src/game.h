#pragma once
#include "window\window.h"



namespace peake {

class Game
{
public:
	Game();
	~Game();
private:
	window::Window window_;
	void loop();
};


}//namespace peake
