#include "Gift.h"
#include "Mouse.h"

Gift::Gift(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture)
	: StaticObject(position, size, texture)
{}

void Gift::handleCollision(Mouse& otherObject)
{
	this->remove();
	otherObject.handleCollision(*this);
}