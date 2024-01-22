#pragma once

#include "Board.h"
#include "Location.h"
#include "Mouse.h"
#include "Cats.h"

enum Characters {
	mouse
};
class Controller {
public:
	Controller();	//Constructor
	void play();	//start the game

private:
	void resetScreen();
	void handleKey();
	bool handleRegularKey(int c);
	void handleSpecialKey();
	void movePlayer(auto& player, const Location& direction);
	void endGame();

	Location getMouseLocation();
	std::vector<Location> getCatsLocations();
	std::vector<Location> getCheeseLocations();

	Board m_board;
	Mouse m_mouse;
	Cats m_cats;

	int m_whoseTurn;
	int m_level;
	bool m_gameOver;
};