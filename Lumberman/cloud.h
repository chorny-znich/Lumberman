//=================================================================================================
//	Cloud																						===
//=================================================================================================

#pragma once

#include "Lumberman.h"

class Cloud : public dr::DynamicObject
{
public:
	void	init();
	void	update(sf::Time dt);
	void	render(sf::RenderWindow& window);
};