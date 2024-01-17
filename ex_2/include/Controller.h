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
	void handleKey();
	bool handleRegularKey(int c);
	void handleSpecialKey();
	void movePlayer(auto& player, const Location& direction);
	Location getCharacterLocation(Characters requestedCharacter);
	Board m_board;
	int m_level;
	Mouse m_mouse;
};