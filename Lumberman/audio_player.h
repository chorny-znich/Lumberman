#pragma once
#include "Lumberman.h"
#include <SFML/Audio.hpp>
#include <unordered_map>

/**
 * @brief Audio objects manager
*/
class AudioPlayer
{
private:
	std::unordered_map<std::string, sf::Sound> mSounds;
	
	static AudioPlayer* mpAudioPlayer;

public:
	AudioPlayer();

	static void init();
	static void	play(const std::string& sound);
};