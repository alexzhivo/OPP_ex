#pragma once

#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <ctime>
#include "HUD.h"
#include "Wall.h"
#include "Cheese.h"
#include "Door.h"
#include "Key.h"
#include "FreezeGift.h"
#include "LifeGift.h"
#include "TimeGift.h"
#include "EnemyRemoveGift.h"
#include "Cat.h"
#include "Mouse.h"

const int BOARD_WIDTH = 1200;
const int BOARD_HEIGHT = 700;

const int HUD_WIDTH = 1200;
const int HUD_HEIGHT = 100;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

enum Direction { UP , RIGHT , DOWN , LEFT };

class Board {
public:
	Board(GraphicManager& graphicManager, std::string fileName, const int level);
	~Board() = default;
	
	// set
	void upLevel();
	void restartClock();
	void resetBoard();
	void resetPlayer();

	// get
	int getLevel() const;
	int getCurrentTime() const;
	int getScore() const;
	bool isPlayerDead() const;

	bool loadLevelFromFile(const std::string fileName, const int lvl);
	// movement control
	void movePlayer(const Direction direction, const float dtSeconds);
	void moveEnemies(const float dtSeconds);
	void restartLevel();
	void updateObjects(const float dtSeconds);	// updates objects
	CollisionType checkCollisions();	// check for collisions
	void handleCollisions(GameObject& gameObject);

	bool removeRandomEnemy();
	bool freezeEnemies(const float seconds);
	void addTime(const float seconds);

	void draw(sf::RenderWindow& window);
private:
	void addRandomGift(const sf::Vector2f position, const float tileScale);
	void scaleBoard();

	std::unique_ptr<MovingObject> m_player;
	std::vector<std::unique_ptr<MovingObject>> m_enemies;
	std::vector<std::unique_ptr<StaticObject>> m_gameObjects;

	// for freezing enemies
	bool m_isFreezingEnemies = false;
	float m_freezeDuration = 0.0f;
	float m_elapsedFreezeTime = 0.0f;

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
	sf::Vector2f m_start;
};