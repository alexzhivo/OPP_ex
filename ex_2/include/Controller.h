#pragma once

#include "Board.h"
#include "Location.h"

class Controller
{
public:
	Controller();	//Constructor
	void play();	//start the game

private:
	void resetScreen();

	Board m_board;
	int m_level;
};