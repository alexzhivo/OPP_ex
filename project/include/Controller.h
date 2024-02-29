#pragma once

#include "GraphicManager.h"
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
	//void showLose();

	SoundManager m_soundManager;
	GraphicManager m_graphicManager;
	sf::RenderWindow m_window;
	Menu m_menu;
	Board m_board;
};