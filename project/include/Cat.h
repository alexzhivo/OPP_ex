#pragma once

#include "MovingObject.h"

const float CAT_SPEED = 100.f;

class Cat : public MovingObject {
public:
	Cat(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~Cat() = default;
private:
};