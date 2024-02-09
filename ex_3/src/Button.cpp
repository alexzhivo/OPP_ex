#include "Button.h"

Button::Button(const sf::Vector2f& pos, const sf::Texture& texture)
	: m_position(pos) , m_size(80,80) , m_color(sf::Color(200,200,200)), m_isActive(false)
{
	m_sprite.setTexture(texture);
}

void Button::draw(sf::RenderWindow& window)
{
	auto button = sf::RectangleShape(m_size);
	button.setFillColor(m_color);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::White);
	button.setPosition(m_position);
	window.draw(button);
	m_sprite.setPosition(sf::Vector2f(m_position.x + 8,m_position.y + 8));
	window.draw(m_sprite);
}

bool Button::isClicked(const float x, const float y)
{
	if (x >= m_position.x && x <= m_position.x + 80 &&
		y >= m_position.y && y <= m_position.y + 80) {
		pressButton();
		return true;
	}
	return false;
}

void Button::pressButton()
{
	if (m_color == sf::Color(200, 200, 200)) {
		m_color = sf::Color(80, 80, 80);
		m_isActive = true;
	}
	else {
		m_color = sf::Color(200, 200, 200);
		m_isActive = false;
	}
}

bool Button::isActive() const
{
	return m_isActive;
}

void Button::deactivate()
{
	m_color = sf::Color(200, 200, 200);
	m_isActive = false;
}