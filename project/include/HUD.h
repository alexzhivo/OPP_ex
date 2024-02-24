#pragma once

#include <SFML/Graphics.hpp>
#include "GraphicManager.h"

class HUD {
public:
	HUD(GraphicManager& graphicManager);
	~HUD() = default;

	void updateAndDraw(sf::RenderWindow& window, 
		const int level, const int lives, const int keys, 
		const int score, const int time);
private:
	void setTimeString(const int time);

	GraphicManager& m_graphicManager;

	// textures
	sf::Sprite m_background;
	sf::Sprite m_key;
	sf::Sprite m_heart;

	// text
	sf::Text m_level, m_score, m_time;
};