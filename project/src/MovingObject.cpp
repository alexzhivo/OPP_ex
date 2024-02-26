#include "MovingObject.h"

MovingObject::MovingObject(const sf::Vector2f position, const float size,
	sf::Texture* frontTexture,
	sf::Texture* leftTexture,
	sf::Texture* backTexture,
	sf::Texture* rightTexture)
	: GameObject(position, size, frontTexture) , m_speed(0) , m_alive(true) , m_lastPosition(position), m_textures()
{
	m_textures[0] = frontTexture;
	m_textures[1] = leftTexture;
	m_textures[2] = backTexture;
	m_textures[3] = rightTexture;
}

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

void MovingObject::switchTexture(const int side)
{
	m_sprite.setTexture(*m_textures[side]);
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