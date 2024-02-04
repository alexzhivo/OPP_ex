#pragma once

#include <SFML/Graphics.hpp>
#include <Button.h>

class Menu {
public:
	Menu(const float width, const float height, const sf::Color& color);
	void draw(sf::RenderWindow& window);
private:
	void drawButtons(sf::RenderWindow& window);

	std::vector<Button> m_buttons;
	sf::Color m_color;
	sf::Vector2f m_size;	// (width,height)
};