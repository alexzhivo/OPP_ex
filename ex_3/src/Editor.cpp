#include "Editor.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Editor::Editor()
{}

void Editor::run()
{
	auto window = sf::RenderWindow(sf::VideoMode(960, 720), "Level Maker", sf::Style::Titlebar | sf::Style::Close);

	auto board = sf::RectangleShape(sf::Vector2f(640, 640));
	board.setFillColor(sf::Color::White);
	board.setPosition(sf::Vector2f(280, 40));

	const int numRectangles = 10;
	const int cols = 2;
	const int rectWidth = 80;
	const int rectHeight = 80;

	sf::RectangleShape rectangles[numRectangles];

	for (int i = 0; i < numRectangles; ++i) {
		rectangles[i].setSize(sf::Vector2f(rectWidth, rectHeight));
		rectangles[i].setFillColor(sf::Color::Black);
		rectangles[i].setOutlineThickness(5);
		rectangles[i].setOutlineColor(sf::Color::White);

		// Calculate position based on columns
		int col = i % cols;
		int row = i / cols;

		rectangles[i].setPosition((float)(40 + col * (rectWidth + 40)), (float)(80 + row * (rectHeight + 40)));
	}

	while (window.isOpen())
	{
		window.clear();
		window.draw(board);
		for (int i = 0; i < numRectangles; ++i) {
			window.draw(rectangles[i]);
		}
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