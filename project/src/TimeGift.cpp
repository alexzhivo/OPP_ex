#include "TimeGift.h"
#include "Mouse.h"

TimeGift::TimeGift(const sf::Vector2f position, const float size, sf::Texture* texture)
	: Gift(position, size, texture)
{}

void TimeGift::handleCollision(Mouse& otherObject)
{
	this->remove();
	otherObject.increaseScore(5);
	otherObject.handleCollision(*this);
}