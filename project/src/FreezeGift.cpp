#include "FreezeGift.h"
#include "Mouse.h"

FreezeGift::FreezeGift(const sf::Vector2f position, const float size, sf::Texture* texture)
	: Gift(position, size, texture)
{}

void FreezeGift::handleCollision(Mouse& otherObject)
{
	this->remove();
	otherObject.increaseScore(5);
	otherObject.handleCollision(*this);
}