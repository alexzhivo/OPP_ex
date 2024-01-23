#pragma once

#include "Board.h"
#include "Location.h"
#include "io.h"

class Cats {
public:
	Cats(std::vector<Location> positions);

	bool move(Board& board);
	bool isValidMove(Board board, Location location);

	Location getRandomDirection();
	int getRandomNumber(int min, int max);
	void print(Board& board);
	int getNumOfCats();
	Location getCatPosition(const int num);

private:
	std::vector<Location> m_positions;
	const char m_char = '^';
};