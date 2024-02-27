#include "Cheese.h"
#include "Mouse.h"

Cheese::Cheese(const sf::Vector2f position, const float size, sf::Texture* texture)
	: StaticObject(position, size, texture)
{
	++m_numOfCheese;
}

Cheese::~Cheese()
{
	--m_numOfCheese;
}

int Cheese::m_numOfCheese = 0;

int Cheese::getNumOfCheese()
{
	return m_numOfCheese;
}

void Cheese::handleCollision(Mouse& otherObject)
{
	this->remove();
	otherObject.increaseScore(25);
	otherObject.handleCollision(*this);
}