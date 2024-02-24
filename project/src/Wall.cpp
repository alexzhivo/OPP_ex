#include "Wall.h"
#include "Mouse.h"

Wall::Wall(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture)
	: StaticObject(position, size, texture)
{}

void Wall::handleCollision(Mouse& otherObject)
{
	otherObject.handleCollision(*this);
}