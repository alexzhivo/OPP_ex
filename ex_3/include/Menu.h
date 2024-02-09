#pragma once

#include <Button.h>
#include <thread>
#include <chrono>

class Menu {
public:
	Menu(const float width, const float height, 
		 const sf::Color& color , const std::vector<sf::Texture>& textures);
	void draw(sf::RenderWindow& window);

	int buttonClicked(const float x, const float y);
	int getActiveButton() const;

private:
	void drawButtons(sf::RenderWindow& window);
	void createButtons();
	void deactivateOtherButtons(const int index);

	int m_activeButton;

	const std::vector<sf::Texture>* m_textures;
	std::vector<Button> m_buttons;
	sf::Color m_color;
	sf::Vector2f m_size;	// (width,height)
};