#pragma once

#include "MovingObject.h"

const float MOUSE_SPEED = 300.f;

class Mouse : public MovingObject {
public:
	Mouse(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~Mouse() = default;

	void reduceLifeCount();
private:
	int m_lives;
};