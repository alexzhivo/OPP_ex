#include "Cats.h"

Cats::Cats(std::vector<Location> positions) 
	: m_positions(positions) {}

void Cats::print()
{
    for (const auto& cheeseLocation : m_positions) 
    {
        Screen::setLocation(cheeseLocation);
        std::cout << m_char;
    }
}