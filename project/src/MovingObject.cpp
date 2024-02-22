#include "MovingObject.h"

MovingObject::MovingObject(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture)
	: GameObject(position, size, texture) , m_speed(0) , m_alive(true) , m_lastPosition(position)
{}

void MovingObject::setSpeed(float speed)
{
	m_speed = speed;
}

void MovingObject::eliminate()
{
	m_alive = false;
}

bool MovingObject::isAlive() const
{
	return m_alive;
}

void MovingObject::setToLastPosition()
{
	m_sprite.setPosition(m_lastPosition);
}

void MovingObject::move(float offsetX, float offsetY, float deltaTime) {
	m_lastPosition = m_sprite.getPosition();	// for collisions

	float distanceX = offsetX * m_speed * deltaTime;
	float distanceY = offsetY * m_speed * deltaTime;
	m_sprite.move(distanceX, distanceY);
}