#pragma once

#include "Wall.h"
#include <vector>
#include <string>
#include <memory>
#include <fstream>

const int BOARD_WIDTH = 1200;
const int BOARD_HEIGHT = 700;

class Board {
public:
	Board(std::string fileName);
	~Board() = default;
	void loadLevelFromFile(std::string fileName);
	void setTileSize();

	void draw(sf::RenderWindow& window);

	// for collision checking
	sf::FloatRect getBoardBounds() const;
private:
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;

	sf::RectangleShape m_background;
	int m_numOfCols;
	int m_numOfRows;;
	sf::Vector2f m_tileSize;
};