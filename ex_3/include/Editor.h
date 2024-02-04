#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"

class Editor {
public:
	Editor();
	void run();
private:
	void handleClick(const sf::Event::MouseButtonEvent& event);

	std::vector<sf::Texture> m_textures;
	std::vector<std::string> m_textureNames;
	Menu m_menu;
};