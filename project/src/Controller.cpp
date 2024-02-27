#include "Controller.h"

Controller::Controller()
	: m_graphicManager() , m_soundManager(), m_window(), m_board(m_graphicManager, "Board1.txt", 1), m_menu(m_graphicManager)
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
	m_window.setFramerateLimit(60);
	m_window.create(sf::VideoMode(1200, 800), "Cat and Mouse");
	m_soundManager.playSound("menumusic", true);

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

	m_soundManager.stopSound("menumusic");
}

void Controller::startGame()
{
	m_window.create(sf::VideoMode(1200, 800), "Cat and Mouse");

	sf::Clock gameClock;

	m_board.restartClock();
	m_window.setFramerateLimit(60);
	m_soundManager.playSound("levelup", false);
	m_soundManager.playSound("levelmusic", true);
	while (m_window.isOpen()) {

		sf::Time deltaTime = gameClock.restart();
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

		if (Cheese::getNumOfCheese() == 0 && m_board.getCurrentTime() > 0)
		{
			std::cout << "cheese = 0" << std::endl;
			
			m_board.upLevel();
			if (!m_board.loadLevelFromFile("Board" + std::to_string(m_board.getLevel()) + ".txt")) {
				m_board.resetBoard();
				m_window.close();
			}
			m_board.restartClock();
			m_soundManager.playSound("levelup", false);
		}
			
		if (m_board.getCurrentTime() < 0 )
		{
			m_board.restartLevel();
			m_board.loadLevelFromFile("Board" + std::to_string(m_board.getLevel()) + ".txt");
			m_board.restartClock();
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

		// trigger enemies movement
		m_board.moveEnemies(dtSeconds);
		
		// check and handle collisions
		switch (m_board.checkCollisions()) {
		case PickUpKey:
			m_soundManager.playSound("pickupkey", false);
			break;
		case PickUpCheese:
			m_soundManager.playSound("pickupcheese", false);
			break;
		case PickUpGift:
			m_soundManager.playSound("pickupgift", false);
			break;
		case OpenDoor:
			m_soundManager.playSound("opendoor", false);
			break;
		case LoseLife:
			m_soundManager.playSound("loselife", false);
			break;
		case NoCollision:
			break;
		}
		m_board.updateObjects();

		// display updated window
		m_window.clear();
		m_board.draw(m_window);
		m_window.display();

	}
	m_soundManager.stopSound("levelmusic");
}