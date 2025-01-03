//=================================================================================================
//	Axe object																					===
//=================================================================================================

#pragma once

#include "Lumberman.h"

class Axe
{
private:
	sf::Sprite			mSprite;
	gd::Side			mSide;
	bool				mShow;

	const sf::Vector2f	LEFT_POSITION;
	const sf::Vector2f	RIGHT_POSITION;

public:
						Axe();

	void				init();
	void				update(gd::Side side);
	void				render(sf::RenderWindow& window);

	void				setSide(gd::Side side);

	void				isShow(bool show);
};