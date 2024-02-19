#pragma once

#include "StaticObject.h"

class Wall : public StaticObject {
public:
	Wall(const sf::Vector2f position, sf::Vector2f size);
	virtual ~Wall() = default;
private:

};