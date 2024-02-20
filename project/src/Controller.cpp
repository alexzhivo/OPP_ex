#include "Controller.h"

Controller::Controller()
	: m_level(1), m_board("Board.txt")
{}

void Controller::run()
{
	bool running = true;
	while (running)
	{
		m_window.startMenu();
		m_window.startGame(m_board);
	}
}