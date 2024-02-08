#include "Board.h"

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
	board.setPosition(sf::Vector2f(280,0));
	window.draw(board);
	drawTiles(window);
}

void Board::saveBoard()
{
	std::ofstream file("Board.txt", std::ios::trunc);	// clear file
	if (!file.is_open()) {
		std::cerr << "Failed to open the file for writing.\n";
		exit(EXIT_FAILURE);
	} 

	file.seekp(0, std::ios::beg);	// move the writing pointer to the start

	for (int i = 0; i < m_level.size(); i++) {
		for (int j = 0; j < m_level[i].size(); j++) {
			file << m_level[i].at(j).getValue();
		}
		file << '\n';
	}

	file.close();
}

void Board::fileInput(std::ifstream& file)
{
	std::cout << "Loading board from file...\n";
	std::string line;
	int row_num = 0;
	while (std::getline(file, line)) {
		m_size.x = (float)line.size();
		// add a row to m_level
		m_size.y++;
		m_level.push_back(Row((int)line.size()));

		// Process each char in the line
		for (int i = 0; i < line.size(); i++) {
			m_level[row_num].at(i).setValue(line.at(i));

		}
		++row_num;
	}

	file.close(); // Close the file when done
	std::cout << "file has loaded.\n";
}


void Board::clearBoard()
{
	m_level.clear();
	userSizeInput();
}

sf::Vector2i Board::getPressedTile(const int x, const int y) const
{
	sf::Vector2i tilePos;
	int newX = x - (280 + (640 - (int)m_tileDimensions.x * getNumOfCols()) / 2);
	int newY = y - ((640 - (int)m_tileDimensions.y * getNumOfRows()) / 2);

	tilePos.x = (int)(newX / m_tileDimensions.x + 1);
	tilePos.y = (int)(newY / m_tileDimensions.y + 1);

	return tilePos;
}

void Board::handleClick(const int x, const int y, const int buttonNum)
{
	float boundX = float(280) + ((float(640) - m_tileDimensions.x * getNumOfCols()) / 2);
	float boundY = float(640 - m_tileDimensions.y * getNumOfRows()) / 2;

	if (x >= boundX && x <= boundX + m_tileDimensions.x * getNumOfCols() &&
		y >= boundY && y <= boundY + m_tileDimensions.y * getNumOfRows()) {
		if (buttonNum >= 2 && buttonNum <= 9) {
			updateTile(getPressedTile(x, y), buttonNum);
		}
	}
}

void Board::updateTile(const sf::Vector2i tile, const int buttonNum)
{
	if (m_level[tile.y - 1].at(tile.x - 1).getValue() == '%') {
		// trying to erase mouse
		return;
	}
	switch (buttonNum) {
	case 2:
		eraseMouse();
		m_level[tile.y - 1].at(tile.x - 1).setValue('%');
		break;
	case 3:
		m_level[tile.y - 1].at(tile.x - 1).setValue('^');
		break;
	case 4:
		m_level[tile.y - 1].at(tile.x - 1).setValue('#');
		break;
	case 5:
		m_level[tile.y - 1].at(tile.x - 1).setValue('*');
		break;
	case 6:
		m_level[tile.y - 1].at(tile.x - 1).setValue('D');
		break;
	case 7:
		m_level[tile.y - 1].at(tile.x - 1).setValue('$');
		break;
	case 8:
		m_level[tile.y - 1].at(tile.x - 1).setValue(' ');
		break;
	case 9:
		m_level[tile.y - 1].at(tile.x - 1).setValue('F');
		break;
	}
}

void Board::eraseMouse()
{
	for (int i = 0; i < m_level.size(); i++) {
		for (int j = 0; j < m_level[i].size(); j++) {
			if (m_level[i].at(j).getValue() == '%') {
				m_level[i].at(j).setValue(' ');
			}
		}
	}
}

void Board::drawTiles(sf::RenderWindow& window) {

	//m_tileDimensions.x = (float)640 / getNumOfCols();
	//m_tileDimensions.y = (float)640 / getNumOfRows();
	m_tileDimensions.x = float(640) / std::max(getNumOfCols(), getNumOfRows());
	m_tileDimensions.y = float(640) / std::max(getNumOfCols(), getNumOfRows());
	
	//auto startPos = sf::Vector2f(280,0);
	auto startPos = sf::Vector2f();
	startPos.x = float(280) + ((float(640) - m_tileDimensions.x * getNumOfCols()) / 2);
	startPos.y = float(640 - m_tileDimensions.y * getNumOfRows())/ 2;

	for (int i = 0; i < getNumOfRows(); i++) {
		for (int j = 0; j < getNumOfCols(); j++) {
			auto tile = sf::RectangleShape(m_tileDimensions);

			tile.setFillColor(sf::Color::Transparent);
			tile.setOutlineThickness(1);
			tile.setOutlineColor(sf::Color(220,220,220));
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

			startPos.x += m_tileDimensions.x;
		}
		//startPos.x = 280;
		startPos.x = float(280) + ((float(640) - m_tileDimensions.x * getNumOfCols()) / 2);
		startPos.y += m_tileDimensions.y;
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

int Board::getNumOfCols() const
{
	return (int)m_size.x;
}

int Board::getNumOfRows() const
{
	return (int)m_size.y;
}

void Board::userSizeInput()
{
	// File does not exist, prompt the user for board size
	std::cout << "Enter the desired board size (width and height): ";
	std::cin >> m_size.x >> m_size.y;

	// Initialize the board with the specified size
	for (int i = 0; i < m_size.y; i++) {
		m_level.push_back(Row((int)m_size.x));
	}
}