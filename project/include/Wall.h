#pragma once

#include "StaticObject.h"

class Wall : public StaticObject {
public:
	Wall(const sf::Vector2f position);
	virtual ~Wall() = default;
private:

};