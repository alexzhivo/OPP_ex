#include "Menu.h"

Menu::Menu(const float width, const float height, const sf::Color& color, const std::vector<sf::Texture>& textures)
	: m_size(width, height), m_color(color), m_textures(&textures), m_activeButton(-1)
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

bool Menu::isClicked(const int x, const int y)
{
	if (x >= 0 && x <= 280 && y >= 40 && y <= 680) {
		for (int i = 0; i < m_buttons.size(); i++) {
			if (m_buttons[i].isClicked(x,y)) {
				std::cout << "button " << i << " is clicked.\n";
				if (!m_buttons[i].isActive()) {
					m_activeButton = -1;
				}
				else {
					m_activeButton = i;
				}
				deactivateOtherButtons(i);
			}
		}
		return true;
	}
	return false;
}

int Menu::getActiveButton() const
{
	return m_activeButton;
}

void Menu::drawButtons(sf::RenderWindow& window)
{
	for (int i = 0; i < m_buttons.size(); i++) {
		m_buttons[i].draw(window);
	}
}

void Menu::createButtons()
{
	if (m_buttons.empty()) {
		for (int i = 0; i < 10; i++) {
			int col = i % 2;
			int row = i / 2;
			auto button_pos = sf::Vector2f((float)40 + col * 120, (float)80 + row * 120);

			m_buttons.push_back(Button(button_pos, (*m_textures)[i]));
		}
	}
}

void Menu::deactivateOtherButtons(const int index)
{
	for (int i = 0; i < m_buttons.size(); i++) {
		if (i != index) {
			m_buttons[i].deactivate();
		}
	}
}