#include "Wall.h"
#include "Mouse.h"
#include "Cat.h"

Wall::Wall(const sf::Vector2f position, const float size, sf::Texture* texture)
	: StaticObject(position, size, texture)
{}

void Wall::handleCollision(Mouse& otherObject)
{
	otherObject.handleCollision(*this);
}

void Wall::handleCollision(Cat& otherObject)
{
	otherObject.handleCollision(*this);
}