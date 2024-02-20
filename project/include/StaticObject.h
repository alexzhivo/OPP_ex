#pragma once

#include "GameObject.h"

class StaticObject : public GameObject {
public:
	StaticObject(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~StaticObject() = default;

	bool isExisting() const;
	void remove();
private:
	bool m_exists;
};