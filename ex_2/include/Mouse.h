#pragma once

#include "Board.h"
#include "io.h"

class Mouse {
public:
	Mouse(Location position);		// mouse constructor

	void setPosition(Location newPosition);	
	bool move(Board& board, Location newLocation);
	bool isValidMove(Board board, Location location);
	int getLives();
	int getKeys();
	void addKey();
	Location getPosition();
	void resetKeys();

	void getEaten(Board& board);

	void print();

private:
	Location m_position;
	const char m_char = '%';
	int m_keys;
	int m_lives;
};