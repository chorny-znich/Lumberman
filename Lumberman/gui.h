//=================================================================================================
//	GUI																							===
//	Time indicator. Display score and level number												===
//=================================================================================================

#pragma once

#include <SFML/Graphics.hpp>
#include "Lumberman.h"

class Gui
{
private:
	sf::Text mScoreText;
	sf::Text mLevelNumberText;
	dr::TimeBar	mTimeBar;

	bool mShowTimebar = true;

public:
	void init();
	void update(float time);
	void render(sf::RenderWindow& window);

	void isShowTimebar(bool isShow);
};