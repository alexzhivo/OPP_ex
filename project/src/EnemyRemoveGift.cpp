#include "EnemyRemoveGift.h"
#include "Mouse.h"

EnemyRemoveGift::EnemyRemoveGift(const sf::Vector2f position, const float size, sf::Texture* texture)
	: Gift(position, size, texture)
{}

void EnemyRemoveGift::handleCollision(Mouse& otherObject)
{
	this->remove();
	otherObject.increaseScore(5);
	otherObject.handleCollision(*this);
}