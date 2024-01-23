#include "Mouse.h"
#include "io.h"
#include "Location.h"
#include <iostream>

Mouse::Mouse(Location position)
	: m_position(position), m_keys(0) , m_score(0) , m_lives(3) {}

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
		if (theChar == '*') {
			board.clearCheese(newLocation);
			m_score += 10;
		}
		// if mouse steps on key block
		if (theChar == 'F') {
			board.clearCell(newLocation);
			m_keys++;	// adds a key
		}
		// if mouse steps on a Door with key
		if (theChar == 'D') {
			board.clearCell(newLocation);
			m_score += 2;
		}
		// if mouse steps on a Present
		if (theChar == '$') {
			board.clearCell(newLocation);
			m_score += 5;
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
	if (currentChar == 'D' && m_keys > 0) {
		m_keys--; // uses a key
		return true;
	}

	return false;
}

void Mouse::levelUP()
{
	m_keys = 0;				// reset keys for mouse
	m_score += 25;			// adds the points for completing level
}

int Mouse::getLives()
{
	return m_lives;
}
int Mouse::getScore()
{
	return m_score;
}
int Mouse::getKeys()
{
	return m_keys;
}