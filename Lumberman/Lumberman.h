#pragma once
#include <DisRealityGF.h>

/**
 * @brief Common headers and shared data
*/
namespace gd
{
	enum class Screens
	{
		MENU,
		GAME,
		PAUSE,
		RECORD
	};
	enum class Side
	{
		NONE,
		LEFT,
		RIGHT
	};
	const sf::Vector2f GAME_RESOLUTION{ 1920.f, 1080.f };
	const sf::FloatRect GAME_VIEW { 0.0f, 0.0f, 1920.0f, 1080.0f };

	const std::string RECORDS_FILENAME = "data/records.txt";

	const size_t NUM_CLOUDS = 3;
	const size_t NUM_BRANCHES = 6;
}