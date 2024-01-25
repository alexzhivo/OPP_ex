#pragma once

#include "Board.h"
#include "io.h"

class Mouse {
public:
	Mouse(Location position);
	bool move(Board& board, Location newLocation);
	bool isValidMove(Board board, Location location);
	void setPosition(Location newPosition);	
	void print();
	void addKey();
	void getEaten(Board& board);
	void resetKeys();

	int getKeys() const;
	int getLives() const;
	Location getPosition() const;

private:
	const char m_char = '%';
	Location m_position;
	int m_keys;
	int m_lives;
};