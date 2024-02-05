#pragma once

#include <SFML/Graphics.hpp>
#include "Row.h"

class Board {
public:
	Board(const std::vector<sf::Texture>& textures);
	void draw(sf::RenderWindow& window);

	int getNumOfRows() const;
	int getNumOfCols() const;
private:
	void drawTiles(sf::RenderWindow& window);
	void drawSprite(sf::RenderWindow& window, const int spriteID, const sf::RectangleShape& tile);
	void resizeAndCenterSprite(sf::Sprite& sprite, const sf::RectangleShape& tile);
	void userSizeInput();

	const std::vector<sf::Texture>* m_textures;
	std::vector<Row> m_level;
	sf::Vector2f m_size;
};