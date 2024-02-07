#pragma once

#include "Menu.h"
#include "Board.h"

const int SCREEN_WIDTH = 920;
const int SCREEN_HEIGHT = 640;

class Editor {
public:
	Editor();
	void run();
private:
	void handleMouseClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window);

	std::vector<sf::Texture> m_textures;
	std::vector<std::string> m_textureNames;

	Menu m_menu;
	Board m_board;
};