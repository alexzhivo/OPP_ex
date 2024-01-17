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

void Mouse::move(Board &board, Location newLocation)
{
	m_position = newLocation;
}