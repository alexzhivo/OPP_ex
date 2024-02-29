#pragma once

#include "StaticObject.h"

class Cheese : public StaticObject {
public:
	Cheese(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~Cheese();

	// double dispatch handling collision
	void handleCollision(Mouse& otherObject) override;
	void handleCollision(Cat&) override { ; };

	static int getNumOfCheese();
private:
	static int m_numOfCheese;
};