#include "StaticObject.h"

StaticObject::StaticObject(const sf::Vector2f position, sf::Vector2f size)
	: GameObject(position, size) , m_exists(true)
{}

bool StaticObject::isExisting() const
{
	return m_exists;
}

void StaticObject::remove()
{
	m_exists = false;
}