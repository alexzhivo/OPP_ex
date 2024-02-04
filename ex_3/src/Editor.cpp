#include <iostream>
#include "Editor.h"

Editor::Editor()
	: m_menu(280, 640, sf::Color(100, 100, 100), m_textures), m_board(),
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
				break;
			case sf::Event::MouseButtonReleased:
				handleClick(event.mouseButton);
				break;
			}
		}
	}
}

void Editor::handleClick(const sf::Event::MouseButtonEvent& event)
{
	std::cout << event.x << " " << event.y << std::endl;
}