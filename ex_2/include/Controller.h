#pragma once

#include "Location.h"
#include "Mouse.h"
#include "Cats.h"

class Controller {
public:
	Controller();				// constructor
	void play();				// start the game

private:
	void resetScreen();	
	void printEndMessage(const char stat);
	void handleKey();
	void handleRegularKey(const int key_pressed);
	void handleSpecialKey();
	void movePlayer(auto& player, const Location& direction);
	void moveCats(auto& player);
	void increaseLevel();
	void setupNextLevel();
	void handleEndOfGame();
	void printGameData();
	int getScore() const;
	Location getMouseLocation() const;
	std::vector<Location> getCatsLocations();
	std::vector<Location> getCheeseLocations();
	

	Board m_board;
	Mouse m_mouse;
	Cats m_cats;

	int m_whoseTurn;
};