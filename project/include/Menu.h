#pragma once

#include <SFML/Graphics.hpp>

enum menu_button { DEFAULT , START_GAME , HELP , EXIT };

class Menu {
public:
	Menu();
	~Menu() = default;

	void drawMenu(sf::RenderWindow& window);
	menu_button getSelectedOption(sf::Vector2f click_location);

private:
	sf::Font m_font;
	sf::RectangleShape m_newGame;
	sf::RectangleShape m_help;
	sf::RectangleShape m_exit;
	sf::Text m_newGameTxt, m_helpTxt, m_exitTxt;
};