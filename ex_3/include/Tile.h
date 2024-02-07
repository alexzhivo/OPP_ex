#pragma once
#include <iostream>

class Tile {
public:
	Tile(const char val = ' ');
	void setValue(const char val);
	char getValue() const;
private:
	char m_val;
};