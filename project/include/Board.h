#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>

class Board {
public:
	Board(std::string fileName);
	~Board() = default;
	void loadLevelFromFile(std::string fileName);
	void setTileSize();
private:
	std::vector<std::string> m_fileBoard;
	int m_numOfCols;
	int m_numOfRows;;
	sf::Vector2f m_tileSize;
};