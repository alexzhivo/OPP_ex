#include "GraphicManager.h"

GraphicManager::GraphicManager()
	: m_ingameTextures()
{
	loadInGameTextures();
}

sf::Texture* GraphicManager::getTexture(const std::string& name)
{
    for (int i = 0; i < m_ingameTextures.size(); i++) {
        if (m_ingameTextures[i]->name == name) {
            return &(m_ingameTextures[i]->texture);
        }
    }

    std::cout << "texture is not found.\n";
    return nullptr;
}

std::unique_ptr<TextureSlot> GraphicManager::loadTextureFromFile(const std::string& name, const std::string& filename)
{
    std::unique_ptr<TextureSlot> slot = std::make_unique<TextureSlot>();

    if (!slot->texture.loadFromFile(filename)) {
        // Failed to load texture
        return nullptr;
    }

    slot->name = name;
    return slot;
}

void GraphicManager::loadInGameTextures()
{
	m_ingameTextures.push_back(loadTextureFromFile("wall", "wall.png"));
	m_ingameTextures.push_back(loadTextureFromFile("mouse", "mouse.png"));
}