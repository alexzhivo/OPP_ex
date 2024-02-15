#pragma once

#include "Window.h"

class Controller {
public:
	Controller() = default;
	~Controller() = default;
	void run();
private:
	Window m_window;
};