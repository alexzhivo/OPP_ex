#pragma once

#include "StaticObject.h"

class Door : public StaticObject {
public:
	Door(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~Door() = default;
private:
};