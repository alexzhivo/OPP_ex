#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
	Button(const sf::Vector2f& pos , const sf::Texture& texture);
	void draw(sf::RenderWindow& window);
private:
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	sf::Color m_color;
	sf::Sprite m_sprite;
};