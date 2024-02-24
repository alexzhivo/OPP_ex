#include "HUD.h"

HUD::HUD(GraphicManager& graphicManager)
	: m_graphicManager(graphicManager), m_background() , m_key(), m_heart()
{
	m_background.setTexture(*m_graphicManager.getTexture("HUD-background"));
	m_background.setPosition(sf::Vector2f(0, 700));

	m_level.setFont(*graphicManager.getFont());
	m_score.setFont(*graphicManager.getFont());
	m_time.setFont(*graphicManager.getFont());
	m_level.setCharacterSize(32);
	m_score.setCharacterSize(32);
	m_time.setCharacterSize(32);
	m_level.setFillColor(sf::Color(150,130,90));
	m_score.setFillColor(sf::Color(150, 130, 90));
	m_time.setFillColor(sf::Color(150, 130, 90));
	m_level.setPosition(sf::Vector2f(110, 730));
	m_score.setPosition(sf::Vector2f(880, 730));
	m_time.setPosition(sf::Vector2f(1091, 730));

	m_key.setTexture(*m_graphicManager.getTexture("key"));
	m_key.setPosition(sf::Vector2f(575, 735));
	m_key.scale(0.5f, 0.5f);

	m_heart.setTexture(*m_graphicManager.getTexture("heart"));
	m_heart.setPosition(sf::Vector2f(299,728));
	m_heart.scale(0.7f, 0.7f);

}

void HUD::updateAndDraw(sf::RenderWindow& window, const int level, const int lives, 
	const int keys, const int score, const int time)
{
	window.draw(m_background);

	// show level
	m_level.setString(std::to_string(level));
	window.draw(m_level);

	// show keys
	for (int i = 0; i < keys && i < 3; i++) {
		window.draw(m_key);
		m_key.setPosition(sf::Vector2f(575.f + 45.5f * i, 735.f));
	}

	// show hearts
	for (int i = 0; i < lives && i < 3; i++) {
		window.draw(m_heart);
		m_heart.setPosition(sf::Vector2f(299.f + 45.5f * i, 728.f));
	}

	// show score
	m_score.setString(std::to_string(score));
	window.draw(m_score);

	// show time
	setTimeString(time);
	window.draw(m_time);
}

void HUD::setTimeString(const int time)
{
	auto minuteTens = time;
	auto minuteOnes = time;
	auto secondTens = time;
	auto secondOnes = time;
	
	// Calculation of seconds
	secondOnes %= 10;
	secondTens %= 60;
	secondTens /= 10;
	// Calculation of minutes
	minuteOnes /= 60;
	minuteTens /= 60;
	minuteOnes %= 10;
	minuteTens /= 10;

	m_time.setString(std::to_string(minuteTens) + std::to_string(minuteOnes)
		+ ":" + std::to_string(secondTens) + std::to_string(secondOnes));
}