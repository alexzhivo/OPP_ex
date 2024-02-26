#include "GraphicManager.h"

GraphicManager::GraphicManager()
    : m_ingameTextures(), m_font()
{
    m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");  // loading font
	loadInGameTextures();                               // loading textures
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

sf::Font* GraphicManager::getFont()
{
    return &m_font;
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
    m_ingameTextures.push_back(loadTextureFromFile("cat", "cat.png"));
    m_ingameTextures.push_back(loadTextureFromFile("mouse", "mouse.png"));
	m_ingameTextures.push_back(loadTextureFromFile("wall", "wall.png"));
    m_ingameTextures.push_back(loadTextureFromFile("cheese", "cheese.png"));
    m_ingameTextures.push_back(loadTextureFromFile("door", "door.png"));
    m_ingameTextures.push_back(loadTextureFromFile("key", "key.png"));
    m_ingameTextures.push_back(loadTextureFromFile("gift", "gift.png"));
    m_ingameTextures.push_back(loadTextureFromFile("HUD-background", "HUDimage.png"));
    m_ingameTextures.push_back(loadTextureFromFile("heart", "heart.png"));
    m_ingameTextures.push_back(loadTextureFromFile("background", "background.png"));
}