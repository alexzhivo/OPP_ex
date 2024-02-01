#pragma once

#include <SFML/Graphics.hpp>

class Levelmaker {
public:
	Levelmaker();
	void run();
private:
	void handleClick(const sf::Event::MouseButtonEvent& event);
};