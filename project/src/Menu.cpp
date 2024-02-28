#include "Menu.h"
#include <iostream>

Menu::Menu(GraphicManager& graphicManager)
	: m_graphicManager(graphicManager), m_background(), m_logo(), m_helpScreen(),
	m_startGameButton(), m_helpButton(), m_exitButton()
{
	m_background.setTexture(*m_graphicManager.getTexture("menu-background"));
	m_background.setScale(sf::Vector2f(0.8f, 0.8f));

	m_logo.setTexture(*m_graphicManager.getTexture("game-logo"));
	m_logo.setPosition(sf::Vector2f(140, 70));

	m_helpScreen.setTexture(*m_graphicManager.getTexture("help-image"));

	//m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	m_startGameButton.setTexture(*m_graphicManager.getTexture("startgamebutton"));
	m_startGameButton.setPosition(sf::Vector2f(400, 350));

	m_helpButton.setTexture(*m_graphicManager.getTexture("helpbutton"));
	m_helpButton.setPosition(sf::Vector2f(400, 500));

	m_exitButton.setTexture(*m_graphicManager.getTexture("exitbutton"));
	m_exitButton.setPosition(sf::Vector2f(400, 650));
}

void Menu::drawMenu(sf::RenderWindow& window) const
{
	if (!m_showHelp) {
		window.draw(m_background);
		window.draw(m_logo);
		window.draw(m_startGameButton);
		window.draw(m_helpButton);
		window.draw(m_exitButton);
	}
	else {
		window.draw(m_helpScreen);
	}
}

void Menu::activateHelp()
{
	m_showHelp = true;
}

bool Menu::isHelpActivated() const
{
	return m_showHelp;
}

menu_button Menu::getSelectedOption(sf::Vector2f click_location)
{
	if (!m_showHelp) {
		if (m_startGameButton.getGlobalBounds().contains((click_location.x), (click_location.y))) {
			return START_GAME;
		}
		else if (m_helpButton.getGlobalBounds().contains((click_location.x), (click_location.y))) {
			return HELP;
		}
		else if (m_exitButton.getGlobalBounds().contains((click_location.x), (click_location.y))) {
			return EXIT;
		}
	}
	else {
		m_showHelp = false;
	}

	return DEFAULT;
}