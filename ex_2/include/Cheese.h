#pragma once

#include "Location.h"
#include "Board.h"
#include "io.h"

class Cheese {
public:
	Cheese(std::vector<Location> positions);

	size_t getTotalCheese();
	void print();

private:
	std::vector<Location> m_positions;
	const char m_char = '*';
};