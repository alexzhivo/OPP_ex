#pragma once

#include "Menu.h"

class Board;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

class Window {
public:
	Window();
	~Window() = default;

	void startMenu();
	void startGame(Board &board);

private:
	Menu m_menu;
	sf::RenderWindow m_window;

};