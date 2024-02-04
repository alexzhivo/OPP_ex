#pragma once

#include <SFML/Graphics.hpp>
#include "Row.h"

class Board {
public:
	Board();
	void draw(sf::RenderWindow& window);

	int getNumOfRows() const;
	int getNumOfCols() const;
private:
	void drawTiles(sf::RenderWindow& window);
	void userSizeInput();
	std::vector<Row> m_level;
	sf::Vector2f m_size;
};