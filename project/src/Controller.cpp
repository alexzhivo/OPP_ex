#include "Controller.h"

Controller::Controller()
	: m_window(), m_menu(), m_graphicManager(), m_board(m_graphicManager, "Board.txt", 1)
{}

void Controller::run()
{
	bool running = true;
	while (running)
	{
		startMenu();
		startGame();
	}
}

void Controller::startMenu()
{
	m_window.create(sf::VideoMode(1200, 800), "Cat and Mouse");

	while (m_window.isOpen())
	{
		for (auto event = sf::Event{}; m_window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
			{
				auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				// for debug //
				std::cout << m_menu.getSelectedOption(location) << std::endl;
				// --------- //

				switch (m_menu.getSelectedOption(location))
				{
				case START_GAME:
					m_window.close();
					break;
				case EXIT:
					m_window.close();
					exit(EXIT_SUCCESS);
				}

				break;
			}
			case sf::Event::Closed:
			{
				m_window.close();
				exit(EXIT_SUCCESS);
				break;
			}
			default:
				break;
			}
		}

		m_window.clear();
		m_menu.drawMenu(m_window);
		m_window.display();
	}
}

void Controller::startGame()
{

	sf::Vector2f tileSize = m_board.getTileSize();

	sf::Clock clock;

	m_window.create(sf::VideoMode(1200, 800), "Cat and Mouse");

	while (m_window.isOpen()) {
		sf::Time deltaTime = clock.restart();
		float dtSeconds = deltaTime.asSeconds();

		for (auto event = sf::Event{}; m_window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				m_window.close();
				exit(EXIT_SUCCESS);
				break;
			}
			default:
				break;
			}
		}

		// Handle player input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			m_board.movePlayer(LEFT, dtSeconds);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			m_board.movePlayer(RIGHT, dtSeconds);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			m_board.movePlayer(UP, dtSeconds);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			m_board.movePlayer(DOWN, dtSeconds);
		}

		m_window.clear();
		m_board.draw(m_window);
		m_window.display();
	}
}