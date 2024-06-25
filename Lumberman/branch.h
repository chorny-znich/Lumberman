//=================================================================================================
//	Branch object																				===
//=================================================================================================

#pragma once

#include "Lumberman.h"

class Branch
{
private:
	sf::Sprite mSprite;
	gd::Side mSide;

public:
	Branch();

	void init();
	void render(sf::RenderWindow& window);

	sf::Sprite&	getSprite();
	void setSide(gd::Side side);
	gd::Side getSide() const;

};