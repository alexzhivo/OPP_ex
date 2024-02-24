#include "Cat.h"
#include "Mouse.h"

Cat::Cat(const sf::Vector2f position, const float size, sf::Texture* texture)
	: MovingObject(position, size, texture)
{
	this->setSpeed(CAT_SPEED);
}

void Cat::handleCollision(GameObject& gameObject)
{
    // double dispatch
    gameObject.handleCollision(*this);
}

void Cat::handleCollision(Mouse& otherObject)
{
	// call the player so it can decrease its own live count
	otherObject.handleCollision(*this);
}