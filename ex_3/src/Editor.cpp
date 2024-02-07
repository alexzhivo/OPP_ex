#include <iostream>
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
		auto window = sf::RenderWindow(sf::VideoMode(960, 720), "Level Maker", sf::Style::Titlebar | sf::Style::Close);

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
					std::cout << m_menu.getActiveButton() << std::endl;
					break;
				}
			}
		}
	}
}

void Editor::handleMouseClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	int menuButton = m_menu.buttonClicked(event.x, event.y);

	switch (menuButton) {
	case 0:
		std::cout << "new button is pressed\n";
		window.close();
		m_board.clearBoard();
		break;
	case 1:
		std::cout << "save button is pressed\n";
		m_board.saveBoard();
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		std::cout << "entity button is pressed\n";
		break;
	}

	if (m_board.isClicked(event.x, event.y, m_menu.getActiveButton())) {
		std::cout << "board is clicked\n";
	}
}