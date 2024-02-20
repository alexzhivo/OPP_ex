#pragma once

#include "Wall.h"
#include "Mouse.h"
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

const int BOARD_WIDTH = 1200;
const int BOARD_HEIGHT = 700;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

class Board {
public:
	Board(std::string fileName);
	~Board() = default;
	void loadLevelFromFile(std::string fileName);
	void setTileSize();
	void setBoardSize();
	void draw(sf::RenderWindow& window);
	float getTileSize();

	// for collision checking
	sf::FloatRect getBoardBounds() const;
private:
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	
	sf::RectangleShape m_background;
	int m_numOfCols;
	int m_numOfRows;;
	float m_tileSize;
	std::vector<std::string> m_fileBoard;
	float m_boardWidth;
	float m_boardHeight;
};