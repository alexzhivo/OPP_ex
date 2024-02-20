#pragma once

#include "Board.h"
#include "Menu.h"

class Controller {
public:
	Controller();
	~Controller() = default;
	void run();

	void startMenu();
	void startGame(Board& board);
private:

	sf::RenderWindow m_window;
	Menu m_menu;

	Board m_board;
	int m_level;
};