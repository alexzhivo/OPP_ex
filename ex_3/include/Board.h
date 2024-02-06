#pragma once

#include <SFML/Graphics.hpp>
#include "Row.h"

class Board {
public:
	Board(const std::vector<sf::Texture>& textures);
	void draw(sf::RenderWindow& window);

	bool isClicked(const int x, const int y, const int button_num);

	int getNumOfRows() const;
	int getNumOfCols() const;
private:
	sf::Vector2f getPressedTile(const int x, const int y) const;
	void updateTile(const sf::Vector2f tile ,const int button_num);

	void drawTiles(sf::RenderWindow& window);
	void drawSprite(sf::RenderWindow& window, const int spriteID, const sf::RectangleShape& tile);
	void resizeAndCenterSprite(sf::Sprite& sprite, const sf::RectangleShape& tile);
	void userSizeInput();
	void fileInput(std::ifstream& file);

	const std::vector<sf::Texture>* m_textures;
	std::vector<Row> m_level;
	sf::Vector2f m_size;
	sf::Vector2f m_tileDimensions;
};