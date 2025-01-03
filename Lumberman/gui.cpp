#include "gui.h"
#include <sstream>
#include "game_stats.h"

void Gui::init()
{ 
	mScoreText = dr::TextManager::get("Score");
	mLevelNumberText = dr::TextManager::get("Level");
	mTimeBar.init({ (gd::GAME_RESOLUTION.x / 2) - 400.f / 2, gd::GAME_RESOLUTION.y - 100.f }, { 400.f, 80.f }, 6.f);
}

void Gui::update(float time)
{
	std::stringstream ss;
	ss << "Очки : " << GameStats::getScore();
	mScoreText.setString(ss.str());

	std::stringstream ssLevel;
	ssLevel << "Уровень : " << GameStats::getLevelNumber();
	mLevelNumberText.setString(ssLevel.str());

	mTimeBar.update(time);
}

void Gui::render(sf::RenderWindow& window)
{
	window.draw(mLevelNumberText);
	window.draw(mScoreText);
	if (mShowTimebar)
	{
		mTimeBar.render(window);
	}
}

void Gui::isShowTimebar(bool isShow)
{
	mShowTimebar = isShow;
}
