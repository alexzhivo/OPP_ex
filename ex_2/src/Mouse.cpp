#include "Mouse.h"
#include "board.h"
#include "Cats.h"
#include "io.h"
#include <iostream>

Mouse::Mouse(Location position)
	: m_position(position), m_keys(0), m_lives(3), m_score(0) {}

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

bool Mouse::move(Board &board, Location newLocation, Cats& cats)
{
	if (isValidMove(board, newLocation))
	{
		m_position = newLocation;

		handleCheese(board, newLocation);
		handleKey(board, newLocation);
		handlePresent(board, newLocation, cats);
		handleCat(board, newLocation, cats);

		return true;
	}

	return false;
}

bool Mouse::isValidMove(Board &board, Location location)
{
	char currentChar = board.getChar(location);

	if (currentChar == ' ' || currentChar == '$' || currentChar == '*' || currentChar == 'F')
		return true;
	if (handleDoor(board, location))
		return true;

	return false;
}

void Mouse::handleCheese(Board& board, const Location& location)
{
	if (board.getChar(location) == '*')
	{
		board.clearItem(location, '*');
		m_score += 10;
	}
}

void Mouse::handleKey(Board& board, const Location& location)
{
	if (board.getChar(location) == 'F')
	{
		board.clearItem(location, 'F');
		addKey();
	}
}

bool Mouse::handleDoor(Board& board, const Location& location)
{
	if (board.getChar(location) == 'D' && m_keys > 0)
	{
		m_keys--;
		board.clearCell(location);
		m_score += 2;
		return true;
	}
	return false;
}

void Mouse::handlePresent(Board& board, const Location& location, Cats& cats)
{
	if (board.getChar(location) == '$')
	{
		board.clearItem(location, '$');
		cats.killCat();
		m_score += 5;
	}
}

void Mouse::handleCat(Board& board, const Location& newLocation, Cats& cats)
{
	for (int i = 0; i < cats.getNumOfCats(); ++i)
	{
		if (board.isSamePosition(newLocation, cats.getCatPosition(i)))
		{
			getEaten(board);
		}
	}
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

int Mouse::getScore() const
{
	return m_score;
}

void Mouse::setScore(int score)
{
	m_score = score;
}