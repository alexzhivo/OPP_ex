#include "Cat.h"

Cat::Cat(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture)
	: MovingObject(position, size, texture)
{
	this->setSpeed(CAT_SPEED);
}