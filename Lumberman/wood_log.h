//=================================================================================================
//	Wood log object																				===
//=================================================================================================

#pragma once

#include "Lumberman.h"
#include "dynamic_object.h"

class WoodLog : public dr::DynamicObject
{
private:
	sf::Vector2f		mSpeed;

public:
	WoodLog();

	void				init() override;
	void				update(sf::Time dt) override;

	void				move(gd::Side side);
};