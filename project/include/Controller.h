#pragma once

#include "Window.h"
#include "Board.h"

class Controller {
public:
	Controller() = default;
	~Controller() = default;
	void run();
private:
	Window m_window;
	Board m_board;
	int m_level;
};