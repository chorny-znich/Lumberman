//=================================================================================================
//	Player object																				===
//=================================================================================================

#pragma once

#include "Lumberman.h"
#include "axe.h"
#include "gravestone.h"

class Player
{
private:
	sf::Sprite			mSprite;
	Axe					mAxe;
	Gravestone			mGravestone;
	gd::Side			mSide;
	bool				mShow;

	const sf::Vector2f	LEFT_POSITION;
	const sf::Vector2f	RIGHT_POSITION;

public:
	Player();
	void				init();
	gd::Side			update();
	void				render(sf::RenderWindow& window);
	
	void				show(bool isShow);
	void				showAxe(bool isShow);
	void				showGravestone(bool isShow);

	void				setSide(gd::Side side);
	gd::Side			getSide() const;

};