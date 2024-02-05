#include "Board.h"
#include <iostream>
#include <fstream>

const int MOUSE_SPRITE_ID = 2;
const int CAT_SPRITE_ID = 3;
const int WALL_SPRITE_ID = 4;
const int CHEESE_SPRITE_ID = 5;
const int DOOR_SPRITE_ID = 6;
const int GIFT_SPRITE_ID = 7;
const int KEY_SPRITE_ID = 9;

Board::Board(const std::vector<sf::Texture>& textures)
	: m_textures(&textures)
{
	std::ifstream file("Board.txt");
	if (file.good())
	{
		// File exists, load the board from the file
		fileInput(file);
	}
	else
	{
		// File does not exists, use user input
		userSizeInput();
	}
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
			tile.setOutlineColor(sf::Color(200,200,200));
			tile.setPosition(startPos);
			window.draw(tile);

			switch (m_level[i].at(j).getValue()) {
			case '%':
				drawSprite(window, MOUSE_SPRITE_ID, tile);
				break;
			case '^':
				drawSprite(window, CAT_SPRITE_ID, tile);
				break;
			case '#':
				drawSprite(window, WALL_SPRITE_ID, tile);
				break;
			case '*':
				drawSprite(window, CHEESE_SPRITE_ID, tile);
				break;
			case 'D':
				drawSprite(window, DOOR_SPRITE_ID, tile);
				break;
			case '$':
				drawSprite(window, GIFT_SPRITE_ID, tile);
				break;
			case 'F':
				drawSprite(window, KEY_SPRITE_ID, tile);
				break;
			default:
				break;
			}

			startPos.x += width;
		}
		startPos.x = 280;
		startPos.y += height;
	}
}

void Board::drawSprite(sf::RenderWindow& window, const int spriteID, const sf::RectangleShape& tile)
{
	sf::Sprite sprite;
	sprite.setTexture((*m_textures)[spriteID]);
	resizeAndCenterSprite(sprite,tile);
	window.draw(sprite);
}

void Board::resizeAndCenterSprite(sf::Sprite& sprite, const sf::RectangleShape& tile) {

	float tileWidth = tile.getSize().x;
	float tileHeight = tile.getSize().y;

	// Get the dimensions of the sprite
	float spriteWidth = static_cast<float>(sprite.getTextureRect().width);
	float spriteHeight = static_cast<float>(sprite.getTextureRect().height);

	// Calculate the scale factors for resizing the sprite to be 5/6 of the tile size
	float scaleX = (5.0f / 6.0f) * (tileWidth / spriteWidth);
	float scaleY = (5.0f / 6.0f) * (tileHeight / spriteHeight);

	// Choose the smaller scale factor to maintain the aspect ratio
	float scaleFactor = std::min(scaleX, scaleY);

	// Resize the sprite
	sprite.setScale(scaleFactor, scaleFactor);

	// Center the sprite inside the square using proportional offsets
	float offsetX = (tileWidth - sprite.getLocalBounds().width * scaleFactor) / 2.0f;
	float offsetY = (tileHeight - sprite.getLocalBounds().height * scaleFactor) / 2.0f;
	sprite.setPosition(tile.getPosition().x + offsetX, tile.getPosition().y + offsetY);
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
	// File does not exist, prompt the user for board size
	std::cout << "Enter the desired board size (height and width): ";
	std::cin >> m_size.x >> m_size.y;

	// Initialize the board with the specified size
	std::cout << "Creating new board...\n";
	for (int i = 0; i < m_size.x; i++) {
		m_level.push_back(Row((int)m_size.y));
	}

	for (int i = 0; i < m_size.x; i++) {
		for (int j = 0; j < m_size.y; j++) {
			std::cout << m_level[i].at(j).getValue();
		}
		std::cout << std::endl;
	}
}


void Board::fileInput(std::ifstream& file)
{
	std::cout << "Loading board from file...\n";
	std::string line;
	int row_num = 0;
	while (std::getline(file, line)) {
		m_size.y = line.size();
		// add a row to m_level
		m_size.x++;
		m_level.push_back(Row((int)line.size()));

		// Process each char in the line
		for (int i = 0; i < line.size() ; i++) {
			m_level[row_num].at(i).setValue(line.at(i));

		}
		++row_num;
	}

	file.close(); // Close the file when done
}
