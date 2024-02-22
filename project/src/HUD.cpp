#include "HUD.h"

HUD::HUD(GraphicManager& graphicManager)
	: m_graphicManager(graphicManager), m_background() , m_key(), m_heart()
{
	m_background.setTexture(*m_graphicManager.getTexture("HUD-background"));
	m_background.setPosition(sf::Vector2f(0, 700));

	m_key.setTexture(*m_graphicManager.getTexture("key"));
	m_key.setPosition(sf::Vector2f(575, 735));
	m_key.scale(0.5f, 0.5f);

	m_heart.setTexture(*m_graphicManager.getTexture("heart"));
	m_heart.setPosition(sf::Vector2f(299,728));
	m_heart.scale(0.7f, 0.7f);

}

void HUD::updateAndDraw(sf::RenderWindow& window, const int level, const int lives, const int keys, const int score)
{
	window.draw(m_background);
	for (int i = 0; i < keys && i < 3; i++) {
		window.draw(m_key);
		m_key.setPosition(sf::Vector2f(575 + i * 45, 735));
	}
	for (int i = 0; i < lives && i < 3; i++) {
		window.draw(m_heart);
		m_heart.setPosition(sf::Vector2f(299 + i * 46, 728));
	}
	window.draw(m_heart);
}