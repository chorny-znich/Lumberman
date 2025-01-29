#pragma once

#include "audio_player.h"
#include "game_stats.h"
#include <DisRealityGF.h>

class Game : public dr::Engine {
private:
  AudioPlayer mAudioPlayer;
  GameStats mGameStats;

  void createStartScreen() override;
  void init() override;
};