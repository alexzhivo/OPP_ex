#pragma once

#include "Menu.h"

class Window {
public:
	Window();
	~Window() = default;

	void startMenu();
	void startGame();

private:
	Menu m_menu;
	sf::RenderWindow m_window;

};