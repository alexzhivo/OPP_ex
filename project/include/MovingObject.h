#pragma once

#include "GameObject.h"

class MovingObject : public GameObject {
public:
	MovingObject(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~MovingObject() = default;

	// set functions
	void setSpeed(float speed);
	void eliminate();

	bool isAlive() const;

	void move(float offsetX, float offsetY, float deltaTime);
private:
	float m_speed;
	bool m_alive;
};