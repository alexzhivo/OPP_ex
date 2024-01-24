#include "Mouse.h"
#include "io.h"
#include <iostream>

Mouse::Mouse(Location position)
	: m_position(position), m_keys(0), m_lives(3) {}

void Mouse::setPosition(Location newPosition)
{
	m_position = newPosition;
}

void Mouse::print()
{
	Screen::setLocation(m_position);
	std::cout << m_char;
}

Location Mouse::getPosition()
{
	return m_position;
}

bool Mouse::move(Board &board, Location newLocation)
{
	if (isValidMove(board, newLocation))
	{
		m_position = newLocation;
		return true;
	}
	return false;
}

bool Mouse::isValidMove(Board board, Location location)
{
	char currentChar = board.getChar(location);
	if (currentChar == ' ' || currentChar == '$' || currentChar == '*' || currentChar == 'F')
		return true;

	if (currentChar == 'D' && m_keys > 0) {
		m_keys--; // uses a key
		return true;
	}

	return false;
}

void Mouse::addKey()
{
	m_keys++;
}

void Mouse::getEaten(Board& board)
{
	m_lives--;
	if (m_lives > 0) 
		m_position = board.getMouseLocation();
}
void Mouse::resetKeys()
{
	m_keys = 0;
}

int Mouse::getLives()
{
	return m_lives;
}

int Mouse::getKeys()
{
	return m_keys;
}
