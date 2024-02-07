#include "Tile.h"

Tile::Tile(const char val)
	: m_val(val) {}

void Tile::setValue(const char val)
{
	m_val = val;
}

char Tile::getValue() const
{
	return m_val;
}