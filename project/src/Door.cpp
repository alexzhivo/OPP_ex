#include "Door.h"
#include "Mouse.h"
#include "Cat.h"

Door::Door(const sf::Vector2f position, const float size, sf::Texture* texture)
	: StaticObject(position, size, texture)
{}

void Door::handleCollision(Mouse& otherObject)
{
	if (otherObject.useKey()) {
		this->remove();
		otherObject.handleCollision(*this);
	}
	else {
		otherObject.setToLastPosition();
	}

}

void Door::handleCollision(Cat& otherObject)
{
	otherObject.handleCollision(*this);
}