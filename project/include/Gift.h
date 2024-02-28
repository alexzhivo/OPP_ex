#pragma once

#include "StaticObject.h"

class Gift : public StaticObject {
public:
	Gift(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~Gift() = default;

private:
};