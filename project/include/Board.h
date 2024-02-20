#pragma once

#include "Wall.h"
#include "Mouse.h"
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#include "GraphicManager.h"

const int BOARD_WIDTH = 1200;
const int BOARD_HEIGHT = 700;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

class Board {
public:
	Board(GraphicManager& graphicManager, std::string fileName, const int level);
	~Board() = default;
	
	// set
	void setTileSize();
	void setBoardSize();
	void upLevel();

	// get
	float getTileSize() const;
	int getLevel() const;

	void draw(sf::RenderWindow& window);
private:
	void loadLevelFromFile(std::string fileName);

	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	
	GraphicManager& m_graphicManager;
	sf::RectangleShape m_background;
	int m_numOfCols;
	int m_numOfRows;;
	float m_tileSize;
	float m_width;
	float m_height;
	int m_level;
};