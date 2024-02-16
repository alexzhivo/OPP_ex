#pragma once

#include <SFML/Graphics.hpp>

class Mouse {
public:
	Mouse(const sf::Vector2f position);
	~Mouse() = default;

	void draw(sf::RenderWindow& window);
	bool isAlive();

	void move(float offsetX, float offsetY, float deltaTime);

private:
	sf::Vector2f m_position;
	sf::RectangleShape m_sprite;

	float m_speed = 200.f;

	bool m_alive = true;
};