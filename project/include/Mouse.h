#pragma once

#include "MovingObject.h"

const float MOUSE_SPEED = 300.f;

class Mouse : public MovingObject {
public:
	Mouse(const sf::Vector2f position);
	virtual ~Mouse() = default;

	void reduceLifeCount();
private:
	int m_lives;
};