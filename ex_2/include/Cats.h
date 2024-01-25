#pragma once

#include "Board.h"
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
	int getNumOfCats() const;
	Location getCatPosition(const int num);
	bool killCat();

private:
	const char m_char = '^';
	std::vector<Location> m_positions;
};