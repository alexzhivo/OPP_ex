#pragma once

#include "Board.h"
#include "Location.h"
#include "io.h"

class Mouse {
public:
	Mouse(Location position);		// mouse constructor

	void setPosition(Location newPosition);	
	bool move(Board& board, Location newLocation);
	bool isValidMove(Board board, Location location);
	int getLives();
	int getScore();
	int getKeys();
	void levelUP();

	Location getPosition();
	void print();

private:
	Location m_position;
	const char m_char = '%';
	int m_keys;
	int m_score;
	int m_lives;
};