#pragma once

#include "Board.h"
#include "Location.h"
#include "io.h"
#include "Mouse.h"

class Cats {
public:
	Cats(std::vector<Location> positions);

	bool move(Board& board, Mouse& mouse);
	bool isValidMove(Board board, Location location);
	void setPositions(std::vector<Location> newPositions);
	Location getRandomDirection();
	int getRandomNumber(int min, int max);
	void print(Board& board);
	int getNumOfCats();
	Location getCatPosition(const int num);

private:
	std::vector<Location> m_positions;
	const char m_char = '^';
};