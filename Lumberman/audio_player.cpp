#include "audio_player.h"

#include <assert.h>
#include <sstream>

AudioPlayer* AudioPlayer::mpAudioPlayer = nullptr;

AudioPlayer::AudioPlayer()
{
	assert(mpAudioPlayer == nullptr);
	mpAudioPlayer = this;
}

void AudioPlayer::init()
{
	auto& ap = mpAudioPlayer->mSounds;

	sf::Sound chop;
	sf::Sound death;
	sf::Sound outOfTime;

	chop.setBuffer(dr::Sounds::get("Chop"));
	death.setBuffer(dr::Sounds::get("Death"));
	outOfTime.setBuffer(dr::Sounds::get("OutOfTime"));

	ap["Chop"] = std::move(chop);
	ap["Death"] = std::move(death);
	ap["OutOfTime"] = std::move(outOfTime);
}

void AudioPlayer::play(const std::string& sound)
{
	auto& ap = mpAudioPlayer->mSounds;

	auto iter = ap.find(sound);
	assert(iter != ap.end());

	iter->second.play();
}