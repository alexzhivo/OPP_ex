#include "Menu.h"

Menu::Menu(const float width, const float height, const sf::Color& color, const std::vector<sf::Texture>& textures)
	: m_size(width, height), m_color(color), m_textures(&textures)
{

}

void Menu::draw(sf::RenderWindow& window)
{
	auto menu = sf::RectangleShape(m_size);
	menu.setFillColor(m_color);
	menu.setPosition(sf::Vector2f(0, 40));
	window.draw(menu);
	createButtons();
	drawButtons(window);
}

bool Menu::isClicked(const int x, const int y) const
{
	if (x >= 0 && x <= 280 && y >= 40 && y <= 680) {
		return true;
	}
	return false;
}

void Menu::drawButtons(sf::RenderWindow& window)
{
	for (int i = 0; i < m_buttons.size(); i++) {
		m_buttons[i].draw(window);
	}
}

void Menu::createButtons()
{
	for (int i = 0; i < 10; i++) {
		int col = i % 2;
		int row = i / 2;
		auto button_pos = sf::Vector2f((float)40 + col * 120, (float)80 + row * 120);

		m_buttons.push_back(Button(button_pos, (*m_textures)[i]));
	}
}