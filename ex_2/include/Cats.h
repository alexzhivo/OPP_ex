#pragma once

#include "Board.h"
#include "Location.h"
#include "io.h"

class Cats {

public:
	Cats(std::vector<Location> positions);
	bool isValidMove(Board board, Location location);
	bool move(Board& board);
	Location getRandomDirection();
	int getRandomNumber(int min, int max);
	void print(Board& board);
private:
	std::vector<Location> m_positions;
	const char m_char = '^';
};