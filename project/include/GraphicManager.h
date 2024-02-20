#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <memory>

struct TextureSlot {
	std::string name;
	sf::Texture texture;
};

class GraphicManager {
public:
	GraphicManager();
	~GraphicManager() = default;

	sf::Texture* getTexture(const std::string& name);

private:
	void loadInGameTextures();
	std::unique_ptr<TextureSlot> loadTextureFromFile(const std::string& name, const std::string& filename);

	std::vector<std::unique_ptr<TextureSlot>> m_ingameTextures;
};