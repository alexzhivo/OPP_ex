#pragma once

#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#include "GraphicManager.h"
#include "HUD.h"
#include "Wall.h"
#include "Cheese.h"
#include "Door.h"
#include "Key.h"
#include "Gift.h"
#include "Cat.h"
#include "Mouse.h"

const int BOARD_WIDTH = 1200;
const int BOARD_HEIGHT = 700;

const int HUD_WIDTH = 1200;
const int HUD_HEIGHT = 100;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

enum Direction { LEFT , RIGHT , UP , DOWN };

class Board {
public:
	Board(GraphicManager& graphicManager, std::string fileName, const int level);
	~Board() = default;
	
	// set
	void upLevel();
	void restartClock();

	// get
	int getLevel() const;
	int getCurrentTime() const;
	
	// for debugging
	void removeObject();
	// -------------

	// movement control
	void movePlayer(const Direction direction, const float dtSeconds);

	void updateObjects();	// removes deleted objects
	void checkCollisions();	// check for collisions

	void draw(sf::RenderWindow& window);
private:
	void loadLevelFromFile(const std::string fileName);
	void scaleBoard();

	std::unique_ptr<GameObject> m_player;
	std::vector<std::unique_ptr<GameObject>> m_enemies;
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;

	GraphicManager& m_graphicManager;
	sf::RectangleShape m_background;
	HUD m_gameHUD;
	sf::Clock m_levelClock;
	int m_totalTime;

	int m_numOfCols;
	int m_numOfRows;;
	float m_tileSize;
	float m_width;
	float m_height;
	int m_level;
};