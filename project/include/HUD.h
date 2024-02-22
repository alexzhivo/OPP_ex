#pragma once

#include <SFML/Graphics.hpp>
#include "GraphicManager.h"

class HUD {
public:
	HUD(GraphicManager& graphicManager);
	~HUD() = default;

	void updateAndDraw(sf::RenderWindow& window, const int level,const int lives,const int keys, const int score);
private:
	GraphicManager& m_graphicManager;

	sf::Sprite m_background;
	sf::Sprite m_key;
	sf::Sprite m_heart;
};