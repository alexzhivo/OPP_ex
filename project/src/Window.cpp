#include "iostream"
#include "Window.h"
#include "Board.h"
#include "Mouse.h"

Window::Window()
	: m_window() , m_menu()
{}

void Window::startMenu()
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

// for mouse debug
void Window::startGame(Board &board)
{

	float tileSize = board.getTileSize();

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
		board.draw(m_window);
		mouse.draw(m_window);
		m_window.display();
	}
}