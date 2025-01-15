#include "game_stats.h"
#include "Lumberman.h"
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <fstream>

GameStats* GameStats::mpInstance = nullptr;

GameStats::GameStats() : mLevelNumber(1), mScore(0)
{
	assert(mpInstance == nullptr);
	mpInstance = this;
	loadRecords("data/records.txt");
}

void GameStats::reset()
{
	mpInstance->mLevelNumber = 1;
	mpInstance->mScore = 0;
}
/*
void GameStats::nextLevel()
{
	mLevelNumber++;
}
*/
const size_t GameStats::getLevelNumber()
{
	return mpInstance->mLevelNumber;
}/*
void GameStats::increaseLevelNumber()
{
	mLevelNumber++;
}

void GameStats::setScore(int score)
{
	mScore = score;
}*/
const int GameStats::getScore() 
{
	return mpInstance->mScore;
}
void GameStats::increaseScore()
{
	mpInstance->mScore++;
}

void GameStats::loadRecords(const std::string& filename)
{
	std::ifstream ifs(filename);
	if (ifs)
	{
		for (size_t i = 0; i < NUM_RECORD_STRINGS; ++i)
		{
			ifs >> mRecords[i];
		}
	}
	else
	{
		std::cout << "Error loading from \"records.txt\"" << std::endl;
	}
}
void GameStats::saveRecords(const std::string& filename)
{
	std::ofstream ofs(filename);
	if (ofs)
	{
		for (size_t i = 0; i < NUM_RECORD_STRINGS; ++i)
		{
			ofs << mpInstance->mRecords[i] << std::endl;
		}
	}
	else
	{
		std::cout << "Error saving to \"data\\records.txt\"" << std::endl;
	}

	ofs.close();
}
void GameStats::checkRecords()
{
	mpInstance->mRecords[4] = mpInstance->mScore > mpInstance->mRecords[4] ? mpInstance->mScore : mpInstance->mRecords[4];
	std::sort(mpInstance->mRecords.begin(), mpInstance->mRecords.end(), [](const auto& first, const auto& second)
		{
			return first > second;
		});
	saveRecords(gd::RECORDS_FILENAME);
}
const std::array<size_t, GameStats::NUM_RECORD_STRINGS>& GameStats::getRecords()
{
	return mpInstance->mRecords;
}