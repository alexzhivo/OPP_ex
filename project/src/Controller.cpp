#include "Controller.h"

Controller::Controller()
	: m_graphicManager() , m_soundManager(), m_window(), m_board(m_graphicManager, "Board1.txt", 1), m_menu(m_graphicManager)
{
	m_window.setFramerateLimit(60);
	m_window.create(sf::VideoMode(1200, 800), "Mouse Maze");
}

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
	m_soundManager.playSound("menumusic", true);	// play music

	while (m_window.isOpen()) {
		for (auto event = sf::Event{}; m_window.pollEvent(event);) {
			switch (event.type) {
			case sf::Event::MouseButtonPressed: 
			{
				sf::Vector2f location;
	
				if (!m_menu.isHelpActivated()) {
					location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				} else {
					m_soundManager.playSound("clicksound", false);
				}

				switch (m_menu.getSelectedOption(location))
				{
				case START_GAME:
					m_soundManager.stopSound("menumusic");
					return;
				case HELP:
					m_soundManager.playSound("clicksound", false);
					m_menu.activateHelp();
					break;
				case EXIT:
					m_window.close();
					exit(EXIT_SUCCESS);
				}
				break;
			}
			case sf::Event::Closed: {
				m_window.close();
				exit(EXIT_SUCCESS);
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
	sf::Clock gameClock;

	m_board.restartClock();
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

		if (m_board.isPlayerDead()) {
			m_soundManager.stopSound("levelmusic");
			m_soundManager.playSound("losesound", false);
			showLose();
			m_board.resetBoard();
			return;
		}

		if (Cheese::getNumOfCheese() == 0 && m_board.getCurrentTime() > 0)
		{
			m_board.upLevel();
			if (!m_board.loadLevelFromFile("Board" + std::to_string(m_board.getLevel()) + ".txt")) {
				m_soundManager.stopSound("levelmusic");
				m_soundManager.playSound("winsound",false);
				showWin();
				m_board.resetBoard();
				return;
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
		case PickUpTime:
			m_board.addTime(15.f);
			m_soundManager.playSound("pickuptime", false);
			break;
		case PickUpEnemyRemove:
			if (m_board.removeRandomEnemy())
				m_soundManager.playSound("pickupenemyremove", false);
			break;
		case PickUpFreeze:
			if (m_board.freezeEnemies(10))
				m_soundManager.playSound("pickupfreeze", false);
			break;
		case OpenDoor:
			m_soundManager.playSound("opendoor", false);
			break;
		case LoseLife:
			m_soundManager.playSound("loselife", false);
			break;
		case PickUpLife:
			m_soundManager.playSound("pickuplife", false);
			break;
		case NoCollision:
			break;
		}
		m_board.updateObjects(dtSeconds);

		// display updated window
		m_window.clear();
		m_board.draw(m_window);
		m_window.display();
	}
	m_soundManager.stopSound("levelmusic");
}

void Controller::showWin()
{
	sf::Text scoreText(std::to_string(m_board.getScore()), *m_graphicManager.getFont(),55);
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setFillColor(sf::Color(100,100,100));
	// position the text in the middle
	sf::FloatRect textBounds = scoreText.getLocalBounds();
	float xPos = (m_window.getSize().x - textBounds.width) / 2.0f;
	scoreText.setPosition(xPos, 420);

	sf::Sprite winscreen;
	winscreen.setTexture(*m_graphicManager.getTexture("winscreen"));

	while (m_window.isOpen()) {
		for (auto event = sf::Event{}; m_window.pollEvent(event);) {
			switch (event.type) {
			case sf::Event::MouseButtonPressed:
			{
				return;
			}
			case sf::Event::Closed: {
				m_window.close();
				exit(EXIT_SUCCESS);
			}
			default:
				break;
			}
		}
		m_window.clear();
		m_window.draw(winscreen);
		m_window.draw(scoreText);
		m_window.display();
	}
}

void Controller::showLose()
{
	sf::Sprite losescreen;
	losescreen.setTexture(*m_graphicManager.getTexture("losescreen"));

	while (m_window.isOpen()) {
		for (auto event = sf::Event{}; m_window.pollEvent(event);) {
			switch (event.type) {
			case sf::Event::MouseButtonPressed:
			{
				return;
			}
			case sf::Event::Closed: {
				m_window.close();
				exit(EXIT_SUCCESS);
			}
			default:
				break;
			}
		}
		m_window.clear();
		m_window.draw(losescreen);
		m_window.display();
	}
}