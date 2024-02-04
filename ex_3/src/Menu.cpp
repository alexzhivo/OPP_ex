#include "Menu.h"

Menu::Menu(const int width, const int height, const sf::Color& color)
	: m_size(width,height), m_color(color)
{}

void Menu::draw(sf::RenderWindow& window)
{
	auto menu = sf::RectangleShape(m_size);
	menu.setFillColor(m_color);
	menu.setPosition(sf::Vector2f(0, 40));
	window.draw(menu);
}