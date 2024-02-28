#pragma once

#include <SFML/Graphics.hpp>
#include "GraphicManager.h"

enum menu_button { DEFAULT , START_GAME , HELP , EXIT };

class Menu {
public:
	Menu(GraphicManager& graphicManager);
	~Menu() = default;

	bool isHelpActivated() const;

	void drawMenu(sf::RenderWindow& window) const;
	menu_button getSelectedOption(sf::Vector2f click_location);

	void activateHelp();

private:
	GraphicManager& m_graphicManager;

	bool m_showHelp = false;

	sf::Sprite m_logo;
	sf::Sprite m_background;
	sf::Sprite m_helpScreen;
	sf::Font m_font;
	sf::RectangleShape m_newGame;
	sf::RectangleShape m_help;
	sf::RectangleShape m_exit;
	sf::Text m_newGameTxt, m_helpTxt, m_exitTxt;
};