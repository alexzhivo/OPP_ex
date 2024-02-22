#pragma once

#include "GameObject.h"

class MovingObject : public GameObject {
public:
	MovingObject(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~MovingObject() = default;

	// set functions
	void setSpeed(float speed);
	void eliminate();
	void setToLastPosition();

	// get functions
	bool isAlive() const;

	void move(float offsetX, float offsetY, float deltaTime);
private:
	sf::Vector2f m_lastPosition;
	float m_speed;
	bool m_alive;
};