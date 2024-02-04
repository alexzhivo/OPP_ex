#include "Board.h"

Board::Board()
{}

void Board::draw(sf::RenderWindow& window)
{
	auto board = sf::RectangleShape(sf::Vector2f(640, 640));
	board.setFillColor(sf::Color::White);
	board.setPosition(sf::Vector2f(280, 40));
	window.draw(board);
}