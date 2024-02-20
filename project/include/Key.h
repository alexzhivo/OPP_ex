#pragma once

#include "StaticObject.h"

class Key : public StaticObject {
public:
	Key(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~Key() = default;
private:
};