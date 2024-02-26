#include "Key.h"
#include "Mouse.h"

Key::Key(const sf::Vector2f position, const float size, sf::Texture* texture)
	: StaticObject(position, size, texture)
{}

void Key::handleCollision(Mouse& otherObject)
{
	if (otherObject.getKeys() < 3) {
		this->remove();
		otherObject.increaseKeys();
		otherObject.handleCollision(*this);
	}
}