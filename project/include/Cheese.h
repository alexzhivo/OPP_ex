#pragma once

#include "StaticObject.h"

class Cheese : public StaticObject {
public:
	Cheese(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~Cheese() = default;
private:
};