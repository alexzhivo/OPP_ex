#include "Editor.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Editor::Editor()
	: m_menu(280,640,sf::Color(100,100,100))
{}

void Editor::run()
{
	auto window = sf::RenderWindow(sf::VideoMode(960, 720), "Level Maker", sf::Style::Titlebar | sf::Style::Close);

	auto board = sf::RectangleShape(sf::Vector2f(640, 640));
	board.setFillColor(sf::Color::White);
	board.setPosition(sf::Vector2f(280, 40));

	while (window.isOpen())
	{
		window.clear();
		m_menu.draw(window);
		window.draw(board);
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