#pragma once

#include <SFML/Graphics.hpp>

class Editor {
public:
	Editor();
	void run();
private:
	void handleClick(const sf::Event::MouseButtonEvent& event);
};