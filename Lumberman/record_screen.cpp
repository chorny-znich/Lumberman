//#include <fstream>
//#include <iostream>
#include <sstream>

#include "game_stats.h"
#include "record_screen.h"
//#include "text_manager.h"

void RecordScreen::init()
{
	mBackground.setTexture(dr::Textures::get("MenuBackground"));
	// Add background images for records
	float positionY = 150.f;
	const float SHIFT = 150.f;
	for (auto& place : mPlaces)
	{
		place.setTexture(dr::Textures::get("WoodLog"));
		place.setPosition({ 810.f, positionY });
		positionY += SHIFT;
	}
	// Add 5 best record as sf::Text objects
	positionY = 160.f;
	const std::array<size_t, NUM_RECORD_STRINGS> records = GameStats::getRecords();

	for (size_t i = 0; i < mRecordText.size(); ++i)
	{
		std::ostringstream oss;
		oss << records[i];
		mRecordText[i] = dr::TextManager::get("RecordValue");
		mRecordText[i].setString(oss.str());
		mRecordText[i].setPosition({ 900.f, positionY + i * SHIFT });
	}
}

void RecordScreen::inputHandler(sf::Vector2i position, sf::RenderWindow* window)
{
}

void RecordScreen::inputHandler(sf::Keyboard::Key key, bool isPressed)
{/*
	if (key == sf::Keyboard::Y && isPressed)
	{
		mChangeState = true;
		mState = "GameScreen";
	}*/
}

void RecordScreen::inputHandler(sf::Mouse::Button button, bool isPressed, sf::Vector2i position, sf::RenderWindow* window)
{
	if (button == sf::Mouse::Left && isPressed)
	{
		dr::GameState::destroyScreen();
	}
}

void RecordScreen::update(sf::Time dt)
{}

void RecordScreen::render(sf::RenderWindow& window)
{
	window.draw(mBackground);

	for (const auto& place : mPlaces)
	{
		window.draw(place);
	}

	for (const auto& record : mRecordText)
	{
		window.draw(record);
	}
}
/*
void RecordScreen::updateRecords()
{
	const std::array<size_t, GameStats::NUM_RECORD_STRINGS> records = GameStats::getRecords();

	for (size_t i = 0; i < mRecordText.size(); ++i)
	{
		std::ostringstream oss;
		oss << records[i];
		mRecordText[i].setString(oss.str());
	}
}

*/