#include "Editor.h"

Editor::Editor()
	: m_menu(280, 640, sf::Color(100, 100, 100), m_textures), m_board(m_textures),
	m_textureNames({ "new","save","mouse","cat","wall","cheese","door","gift","delete","key" })
{
	//load images into m_textures
	for (int i = 0; i < 10; ++i) {
		sf::Texture texture;
		texture.loadFromFile(m_textureNames[i] + ".png");
		m_textures.push_back(texture);
	}
}

void Editor::run()
{
	while (true) {
		auto window = sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Level Editor", sf::Style::Titlebar | sf::Style::Close);

		while (window.isOpen())
		{
			window.clear();
			m_menu.draw(window);
			m_board.draw(window);
			window.display();

			if (auto event = sf::Event{}; window.waitEvent(event)) {
				switch (event.type) {
				case sf::Event::Closed:
					window.close();
					exit(EXIT_SUCCESS);
				case sf::Event::MouseButtonPressed:
					handleMouseClick(event.mouseButton,window);
					break;
				}
			}
		}
	}
}

void Editor::handleMouseClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	// menu press handle
	int menuButton = m_menu.buttonClicked(event.x, event.y);
	switch (menuButton) {
	case 0:		// pressed on new button
		window.close();
		m_board.clearBoard();
		break;
	case 1:		// pressed on save button
		m_board.saveBoard();
		std::cout << "level is saved.\n";
		break;
	default:
		break;
	}
	// board press handle
	m_board.handleClick(event.x, event.y, m_menu.getActiveButton());
}