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
	void resetPosition(Board& board);
	int getLives();
	int getScore();
	int getKeys();
	Location getPosition();
	void levelUP();

	void getEaten(Board& board);

	void print();

private:
	//Location m_startPosition;
	Location m_position;
	const char m_char = '%';
	int m_keys;
	int m_score;
	int m_lives;
};