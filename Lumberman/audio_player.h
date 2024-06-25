#pragma once
#include "Lumberman.h"
#include <SFML/Audio.hpp>

/**
 * @brief Audio objects manager
*/
class AudioPlayer
{
private:
	std::map<std::string, sf::Sound> mSounds;
	
	static AudioPlayer* mpAudioPlayer;

public:
	AudioPlayer();

	static void init();
	static void	play(const std::string& sound);
};