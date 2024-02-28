#include "LifeGift.h"
#include "Mouse.h"

LifeGift::LifeGift(const sf::Vector2f position, const float size, sf::Texture* texture)
	: Gift(position, size, texture)
{}

void LifeGift::handleCollision(Mouse& otherObject)
{
	this->remove();
	otherObject.handleCollision(*this);
}