#include "Cheese.h"
#include "Mouse.h"

Cheese::Cheese(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture)
	: StaticObject(position, size, texture)
{}

void Cheese::handleCollision(Mouse& otherObject)
{
	this->remove();
	otherObject.increaseScore(25);
	otherObject.handleCollision(*this);
}