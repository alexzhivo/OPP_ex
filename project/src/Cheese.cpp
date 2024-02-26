#include "Cheese.h"
#include "Mouse.h"

Cheese::Cheese(const sf::Vector2f position, const float size, sf::Texture* texture)
	: StaticObject(position, size, texture)
{
	++m_numOfChesse;
}

Cheese::~Cheese()
{
	--m_numOfChesse;
}

int Cheese::m_numOfChesse = 0;

int Cheese::getNumOfCheese()
{
	return m_numOfChesse;
}

void Cheese::handleCollision(Mouse& otherObject)
{
	this->remove();
	otherObject.increaseScore(25);
	otherObject.handleCollision(*this);
}