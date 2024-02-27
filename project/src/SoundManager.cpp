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

std::unique_ptr<SoundSlot> SoundManager::loadSoundFromFile(const std::string& name, const std::string& filename, const float volume )
{
    std::unique_ptr<SoundSlot> slot = std::make_unique<SoundSlot>();

    if (!slot->buffer.loadFromFile(filename)) {
        // Failed to load texture
        return nullptr;
    }
    slot->name = name;
    slot->sound.setBuffer(slot->buffer);
    slot->sound.setVolume(volume);

    return slot;
}

void SoundManager::loadSounds()
{
    m_sounds.push_back(loadSoundFromFile("levelup", "levelup.wav", 1.0f));
    m_sounds.push_back(loadSoundFromFile("levelmusic", "levelmusic.wav",0.5f));
    m_sounds.push_back(loadSoundFromFile("menumusic", "menumusic.wav", 0.5f));
    m_sounds.push_back(loadSoundFromFile("opendoor", "opendoor.wav", 5.0f));
    m_sounds.push_back(loadSoundFromFile("pickupcheese", "pickupcheese.wav", 2.0f));
    m_sounds.push_back(loadSoundFromFile("pickupkey", "pickupkey.wav", 2.0f));
    m_sounds.push_back(loadSoundFromFile("pickupgift", "pickupgift.wav", 2.0f));
    m_sounds.push_back(loadSoundFromFile("loselife", "loselife.wav", 3.0f));
}

void SoundManager::playSound(const std::string& name, const bool loop) const
{
    for (int i = 0; i < m_sounds.size(); i++) {
        if (m_sounds[i]->name == name) {
            m_sounds[i]->sound.setLoop(loop);
            m_sounds[i]->sound.play();
        }
    }
}

void SoundManager::stopSound(const std::string& name) const
{
    for (int i = 0; i < m_sounds.size(); i++) {
        if (m_sounds[i]->name == name) {
            m_sounds[i]->sound.stop();
        }
    }
}