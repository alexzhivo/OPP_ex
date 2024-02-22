#pragma once

#include "MovingObject.h"

const float MOUSE_SPEED = 300.f;

class Mouse : public MovingObject {
public:
	Mouse(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~Mouse() = default;

	// double dispatch handling collision
	void handleCollision(GameObject& otherObject) override;
	void handleCollision(Mouse& otherObject) override { ; };
	void handleCollision(Cheese& otherObject) override { ; };
	void handleCollision(Wall& otherObject) override { ; };
	void handleCollision(Gift& otherObject) override { ; };

	void reduceLifeCount();
private:
	int m_lives;
};