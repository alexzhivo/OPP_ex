#pragma once

#include "Board.h"
#include "Location.h"
#include "Mouse.h"

enum Characters {
	mouse
};
class Controller
{
public:
	Controller();	//Constructor
	void play();	//start the game

private:
	void resetScreen();
	Location getCharacterLocation(Characters requestedCharacter);
	Board m_board;
	int m_level;
	Mouse m_mouse;
};