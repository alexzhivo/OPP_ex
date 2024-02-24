#pragma once

#include "Board.h"
#include "Menu.h"
#include "GraphicManager.h"

class Controller {
public:
	Controller();
	~Controller() = default;
	void run();

private:
	void startMenu();
	void startGame();

	sf::RenderWindow m_window;
	Menu m_menu;
	GraphicManager m_graphicManager;
	Board m_board;
};