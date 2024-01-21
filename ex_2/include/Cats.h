

#pragma once

#include "Board.h"
#include "Location.h"
#include "io.h"

class Cats {

public:
	Cats(std::vector<Location> positions);
	//void setPosition(Location newPosition);
	void print();
private:
	std::vector<Location> m_positions;
	const char m_char = '^';
};