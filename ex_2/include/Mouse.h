#pragma once

#include "Board.h"
#include "Location.h"
#include "io.h"

class Mouse {

public:
	Mouse(Location position); 
	void setPosition(Location newPosition);
	void move(Board& board, Location newLocation);
	void print();
	Location getPosition();

private:
	Location m_position;
	const char m_char = '%';
};