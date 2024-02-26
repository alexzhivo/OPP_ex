#pragma once

#include "GameObject.h"

class MovingObject : public GameObject {
public:
	MovingObject(const sf::Vector2f position, const float size,
		sf::Texture* frontTexture,
		sf::Texture* leftTexture,
		sf::Texture* backTexture,
		sf::Texture* rightTexture);
	virtual ~MovingObject() = default;

	// set functions
	void setSpeed(float speed);
	void eliminate();
	void setToLastPosition();

	// get functions
	bool isAlive() const;

	void switchTexture(const int side);
	void move(float offsetX, float offsetY, float deltaTime);
private:
	sf::Texture* m_textures[4];
	sf::Vector2f m_lastPosition;
	float m_speed;
	bool m_alive;
};