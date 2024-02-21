#include "Menu.h"

Menu::Menu()
	: m_font(), m_newGame(), m_help(), m_exit()
{
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	m_newGameTxt.setFont(m_font);
	m_newGameTxt.setString("New Game");
	m_newGameTxt.setPosition(sf::Vector2f(500, 320));
	m_newGameTxt.setCharacterSize(40);
	m_newGameTxt.setFillColor(sf::Color::Black);

	m_newGame.setSize(sf::Vector2f(400, 100));
	m_newGame.setPosition(sf::Vector2f(400, 300));
	m_newGame.setFillColor(sf::Color(200,200,200));

	m_helpTxt.setFont(m_font);
	m_helpTxt.setString("Help");
	m_helpTxt.setPosition(sf::Vector2f(560, 470));
	m_helpTxt.setCharacterSize(40);
	m_helpTxt.setFillColor(sf::Color::Black);

	m_help.setSize(sf::Vector2f(400, 100));
	m_help.setPosition(sf::Vector2f(400, 450));
	m_help.setFillColor(sf::Color(200, 200, 200));

	m_exitTxt.setFont(m_font);
	m_exitTxt.setString("Exit");
	m_exitTxt.setPosition(sf::Vector2f(565, 620));
	m_exitTxt.setCharacterSize(40);
	m_exitTxt.setFillColor(sf::Color::Black);

	m_exit.setSize(sf::Vector2f(400, 100));
	m_exit.setPosition(sf::Vector2f(400, 600));
	m_exit.setFillColor(sf::Color(200, 200, 200));
}

void Menu::drawMenu(sf::RenderWindow& window) const
{
	window.draw(m_newGame);
	window.draw(m_newGameTxt);
	window.draw(m_help);
	window.draw(m_helpTxt);
	window.draw(m_exit);
	window.draw(m_exitTxt);
}

menu_button Menu::getSelectedOption(sf::Vector2f click_location)
{
	if (m_newGame.getGlobalBounds().contains((click_location.x), (click_location.y))) {
		return START_GAME;
	}
	else if (m_help.getGlobalBounds().contains((click_location.x), (click_location.y))) {
		return HELP;
	}
	else if (m_exit.getGlobalBounds().contains((click_location.x), (click_location.y))) {
		return EXIT;
	}
	return DEFAULT;
}