#include "Cats.h"

Cats::Cats(std::vector<Location> positions) 
	: m_positions(positions)
{
}

void Cats::print()
{
    for (const auto& catLocation : m_positions) 
    {
        Screen::setLocation(catLocation);
        std::cout << m_char;
    }
}


