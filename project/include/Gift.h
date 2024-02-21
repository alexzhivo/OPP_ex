#pragma once

#include "StaticObject.h"

class Gift : public StaticObject {
public:
	Gift(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~Gift() = default;
private:
};