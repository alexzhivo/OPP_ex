#include "Mouse.h"
#include "io.h"
#include "Location.h"
#include <iostream>

Mouse::Mouse(Location position)
	: m_position(position) {}

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

		char theChar = board.getChar(newLocation);

		// if mouse steps on cheese block
		if (theChar == '*') 
		{
			board.clearCheese(newLocation);
		}

		return true;
	}
	return false;
}

bool Mouse::isValidMove(Board board, Location location)
{
	char currentChar = board.getChar(location);
	if (currentChar == ' ' || currentChar == '$' || currentChar == '*' || currentChar == 'F')
		return true;

	return false;
}