#pragma once

#include "Menu.h"

class Window {
public:
	Window();
	~Window() = default;

	void startMenu();
private:
	Menu m_menu;
	sf::RenderWindow m_window;
};