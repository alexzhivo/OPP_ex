#pragma once

#include <SFML/Graphics.hpp>
#include "GraphicManager.h"

enum menu_button { DEFAULT , START_GAME , HELP , EXIT };

class Menu {
public:
	Menu(GraphicManager& graphicManager);
	~Menu() = default;

	void drawMenu(sf::RenderWindow& window) const;
	menu_button getSelectedOption(sf::Vector2f click_location);

private:
	GraphicManager& m_graphicManager;

	sf::Sprite m_background;
	sf::Font m_font;
	sf::RectangleShape m_newGame;
	sf::RectangleShape m_help;
	sf::RectangleShape m_exit;
	sf::Text m_newGameTxt, m_helpTxt, m_exitTxt;
};