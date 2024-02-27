#include "SoundManager.h"

SoundManager::SoundManager()
	 : m_sounds()
{
    loadSounds();
    
    // for debug 
    for (int i = 0; i < m_sounds.size(); i++) {
        std::cout << "sound loaded : " << m_sounds.at(i)->name << std::endl;
    }
    // ---------
}

std::unique_ptr<SoundSlot> SoundManager::loadSoundFromFile(const std::string& name, const std::string& filename)
{
    std::unique_ptr<SoundSlot> slot = std::make_unique<SoundSlot>();

    if (!slot->buffer.loadFromFile(filename)) {
        // Failed to load texture
        return nullptr;
    }
    slot->name = name;
    slot->sound.setBuffer(slot->buffer);

    return slot;
}

void SoundManager::loadSounds()
{
    m_sounds.push_back(loadSoundFromFile("levelup", "levelup.wav"));
}

void SoundManager::playSound(const std::string& name) const
{
    for (int i = 0; i < m_sounds.size(); i++) {
        if (m_sounds[i]->name == name) {
            m_sounds[i]->sound.play();
        }
    }
}