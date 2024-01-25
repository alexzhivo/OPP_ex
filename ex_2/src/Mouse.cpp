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

Location Mouse::getPosition() const
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

// mouse picked up a key
void Mouse::addKey()
{
	m_keys++;
}
// mouse get eaten, loses life and returns to initial location
void Mouse::getEaten(Board& board)
{
	m_lives--;
	if (m_lives > 0) 
		m_position = board.getMouseLocation();
}
// reset cats keys
void Mouse::resetKeys()
{
	m_keys = 0;
}
// get current lives
int Mouse::getLives() const
{
	return m_lives;
}

int Mouse::getKeys() const
{
	return m_keys;
}
