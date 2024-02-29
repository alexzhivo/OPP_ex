#pragma once

#include "SoundManager.h"
#include "Board.h"
#include "Menu.h"

class Controller {
public:
	Controller();
	~Controller() = default;
	void run();

private:
	void startMenu();
	void startGame();
	void showWin();
	void showLose();

	sf::RenderWindow m_window;
	SoundManager m_soundManager;
	GraphicManager m_graphicManager;
	Menu m_menu;
	Board m_board;
};