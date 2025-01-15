//=================================================================================================
//	Gravestone object																			===
//=================================================================================================

#pragma once

#include "Lumberman.h"

class Gravestone
{
private:
	sf::Sprite					mSprite;
	bool						mShow{ false };

	const sf::Vector2f			POSITION{ 525.f, 760.f };

public:
	void						init();
	void						render(sf::RenderWindow& window);

	void						isShow(bool show);

};