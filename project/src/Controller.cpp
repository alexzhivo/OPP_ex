#include "Controller.h"

Controller::Controller()
	: m_board("Board.txt",1) , m_window() , m_menu()
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

	float tileSize = m_board.getTileSize();

	Mouse mouse(sf::Vector2f(20, 20), sf::Vector2f(tileSize, tileSize));	// create mouse , getTileSize temporary

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
			mouse.move(-1, 0, dtSeconds);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			mouse.move(1, 0, dtSeconds);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			mouse.move(0, -1, dtSeconds);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			mouse.move(0, 1, dtSeconds);
		}

		m_window.clear();
		m_board.draw(m_window);
		mouse.draw(m_window);
		m_window.display();
	}
}