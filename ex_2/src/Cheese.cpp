#include "Cheese.h"

Cheese::Cheese(std::vector<Location> positions)
	: m_positions(positions) {}

size_t Cheese::getTotalCheese()
{
	return m_positions.size();
}

void Cheese::print()
{
    for (const auto& catLocation : m_positions)
    {
        Screen::setLocation(catLocation);
        std::cout << m_char;
    }
}