#pragma once

#include <Button.h>

class Menu {
public:
	Menu(const float width, const float height, 
		 const sf::Color& color , const std::vector<sf::Texture>& textures);
	void draw(sf::RenderWindow& window);

	bool isClicked(const int x, const int y) const;

private:
	void drawButtons(sf::RenderWindow& window);
	void createButtons();

	const std::vector<sf::Texture>* m_textures;
	std::vector<Button> m_buttons;
	sf::Color m_color;
	sf::Vector2f m_size;	// (width,height)
};