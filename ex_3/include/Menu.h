#pragma once

#include <SFML/Graphics.hpp>

class Menu {
public:
	Menu(const int width, const int height, const sf::Color& color);
	void draw(sf::RenderWindow& window);
private:

	sf::Color m_color;
	sf::Vector2f m_size;	// (width,height)
};