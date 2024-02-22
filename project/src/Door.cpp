#include "Door.h"
#include "Mouse.h"

Door::Door(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture)
	: StaticObject(position, size, texture)
{}

void Door::handleCollision(Mouse& otherObject)
{
	if (otherObject.useKey()) {
		this->remove();
	}
	else {
		otherObject.setToLastPosition();
	}

	otherObject.handleCollision(*this);
}