#pragma once

#include "Location.h"
#include "io.h"

class Mouse {

public:
	Mouse(Location position); 
	void setPosition(Location newPosition);
	void print();

private:
	Location m_position;
	const char m_char = '%';
};