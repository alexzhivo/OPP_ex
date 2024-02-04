#include "Menu.h"

Menu::Menu(const float width, const float height, const sf::Color& color)
	: m_size(width,height), m_color(color)
{
	//create buttons
	for (int i = 0; i < 10; ++i) {
		int col = i % 2;
		int row = i / 2;
		auto button_pos = sf::Vector2f(40 + col * 120, 80 + row * 120);

		m_buttons.push_back(Button(button_pos));
	}
}

void Menu::draw(sf::RenderWindow& window)
{
	auto menu = sf::RectangleShape(m_size);
	menu.setFillColor(m_color);
	menu.setPosition(sf::Vector2f(0, 40));
	window.draw(menu);
	drawButtons(window);
}

void Menu::drawButtons(sf::RenderWindow& window)
{
	for (int i = 0; i < m_buttons.size(); i++) {
		m_buttons[i].draw(window);
	}
}