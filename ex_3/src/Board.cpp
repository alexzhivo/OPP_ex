#include "Board.h"
#include <iostream>
#include <fstream>

Board::Board()
{
	userSizeInput();
}

void Board::draw(sf::RenderWindow& window)
{
	auto board = sf::RectangleShape(sf::Vector2f(640, 640));
	board.setFillColor(sf::Color::White);
	board.setPosition(sf::Vector2f(280, 40));
	window.draw(board);
	drawTiles(window);
}

void Board::drawTiles(sf::RenderWindow& window) {

	float width = (float)640 / getNumOfCols();
	float height = (float)640 / getNumOfRows();

	auto startPos = sf::Vector2f(280, 40);

	for (int i = 0; i < getNumOfRows(); i++) {
		for (int j = 0; j < getNumOfCols(); j++) {
			auto tile = sf::RectangleShape(sf::Vector2f(width, height));
			tile.setFillColor(sf::Color::Transparent);
			tile.setOutlineThickness(1);
			tile.setOutlineColor(sf::Color::Black);
			tile.setPosition(startPos);
			window.draw(tile);
			startPos.x += width;
		}
		startPos.x = 280;
		startPos.y += height;
	}
}

int Board::getNumOfRows() const
{
	return (int)m_size.x;
}

int Board::getNumOfCols() const
{
	return (int)m_size.y;
}

void Board::userSizeInput()
{
	// Check if the input file exists
	std::ifstream inputFile("Board.txt");
	if (inputFile.good())
	{
		// File exists, load the board from the file
		std::cout << "Loading board from file...\n";
	}
	else
	{
		// File does not exist, prompt the user for board size
		std::cout << "Enter the desired board size (height and width): ";
		std::cin >> m_size.x >> m_size.y;

		// Initialize the board with the specified size
		std::cout << "Creating new board...\n";
		for (int i = 0; i < m_size.x; i++) {
			m_level.push_back(Row((int)m_size.y));
		}
	}
}