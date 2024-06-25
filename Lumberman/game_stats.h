//=================================================================================================
//	Game statistics																				===
//=================================================================================================

#pragma once

#include <array>
//#include <memory>
#include <string>

class GameStats
{
public:
	static const size_t	NUM_RECORD_STRINGS = 5;

private:
	size_t mLevelNumber;
	size_t mScore;
	std::array<size_t, NUM_RECORD_STRINGS> mRecords;

	static GameStats* mpInstance;

public:
	GameStats();

	static void	reset();
//	void					nextLevel();

	static const size_t	getLevelNumber();
//	void					increaseLevelNumber();

//	void					setScore(int score);
	static const int getScore();
	static void	increaseScore();
	
	void loadRecords(const std::string& filename);
	static void saveRecords(const std::string& filename);
	static void	checkRecords();
	static const std::array<size_t, NUM_RECORD_STRINGS>& getRecords();
};