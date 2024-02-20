#pragma once

#include "GraphicManager.h"
#include "Wall.h"
#include "Cheese.h"
#include "Door.h"
#include "Key.h"
//#include "Cat.h"
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

enum direction { LEFT , RIGHT , UP , DOWN };

class Board {
public:
	Board(GraphicManager& graphicManager, std::string fileName, const int level);
	~Board() = default;
	
	// set
	void setTileSize();
	void setBoardSize();
	void upLevel();

	// get
	sf::Vector2f getTileSize() const;
	int getLevel() const;

	// movement controll
	void movePlayer(const direction direction, const float dtSeconds);

	void draw(sf::RenderWindow& window);
private:
	void loadLevelFromFile(std::string fileName);

	std::unique_ptr<MovingObject> m_player;
	//std::vector<std::unique_ptr<MovingObject>> m_enemies;
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;

	GraphicManager& m_graphicManager;
	sf::RectangleShape m_background;
	int m_numOfCols;
	int m_numOfRows;;
	sf::Vector2f m_tileSize;
	float m_width;
	float m_height;
	int m_level;
};