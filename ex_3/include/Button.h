#pragma once

#include <SFML/Graphics.hpp>

class Button {
public:
	Button(const sf::Vector2f& pos /*, const sf::Sprite& sprite*/);
	void draw(sf::RenderWindow& window);
private:
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	sf::Color m_color;
	//sf::Sprite m_sprite;
};