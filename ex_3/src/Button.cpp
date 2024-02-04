#include "Button.h"

Button::Button(const sf::Vector2f& pos/*, const sf::Sprite& sprite*/)
	: m_position(pos) , m_size(80,80) , m_color(sf::Color(200,200,200)) /*, m_sprite(sprite)*/
{}

void Button::draw(sf::RenderWindow& window)
{
	auto button = sf::RectangleShape(m_size);
	button.setFillColor(m_color);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::White);
	button.setPosition(m_position);
	window.draw(button);
}