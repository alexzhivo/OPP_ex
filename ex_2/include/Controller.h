#pragma once

#include "Location.h"
#include "Mouse.h"
#include "Cats.h"

enum Characters {
	mouse
};
class Controller {
public:
	Controller();				// constructor
	void play();				// start the game
private:
	void resetScreen();
	void handleRegularKey(int c);
	void handleSpecialKey();
	void handleKey();
	void movePlayer(auto& player, const Location& direction);
	void moveCats(auto& player);
	Location getMouseLocation();
	int getScore();
	void increaseLevel();
	void printEndMessage(const char stat);
	
	std::vector<Location> getCatsLocations();
	std::vector<Location> getCheeseLocations();

	Board m_board;
	Mouse m_mouse;
	Cats m_cats;
	
	int m_score;
	int m_whoseTurn;
};