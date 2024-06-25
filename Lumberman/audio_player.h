//=================================================================================================
//	Manage audio objects																		===
//=================================================================================================

#pragma once

#include "Lumberman.h"

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