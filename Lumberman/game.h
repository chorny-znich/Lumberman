#pragma once

#include "game_stats.h"
#include <DisRealityGF.h>

class Game : public dr::Engine {
private:
	GameStats mGameStats;

  void createStartScreen() override;
  void init() override;
};