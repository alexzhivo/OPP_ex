#include "StaticObject.h"

StaticObject::StaticObject(const sf::Vector2f position)
	: GameObject(position) , m_exists(true)
{}

bool StaticObject::isExisting() const
{
	return m_exists;
}

void StaticObject::remove()
{
	m_exists = false;
}