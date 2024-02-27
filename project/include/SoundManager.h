#pragma once

#include <SFML/Audio.hpp>
#include <iostream> // for debug
#include <string>
#include <memory>

struct SoundSlot {
	std::string name;
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

class SoundManager {
public:
	SoundManager();
	~SoundManager() = default;

	void playSound(const std::string& name) const;

private:
	void loadSounds();
	std::unique_ptr<SoundSlot> loadSoundFromFile(const std::string& name, const std::string& filename);

	std::vector<std::unique_ptr<SoundSlot>> m_sounds;
};