#include "Cat.h"
#include "Mouse.h"

Cat::Cat(const sf::Vector2f position, const float size, sf::Texture* texture)
	: MovingObject(position, size, texture)
{
	this->setSpeed(CAT_SPEED);
}

void Cat::handleCollision(Mouse& otherObject)
{
	otherObject.reduceLifeCount();
	otherObject.handleCollision(*this);
}