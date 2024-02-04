#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"

class Editor {
public:
	Editor();
	void run();
private:
	void handleClick(const sf::Event::MouseButtonEvent& event);

	Menu m_menu;
};