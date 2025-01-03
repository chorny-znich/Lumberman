#pragma once

#include "Lumberman.h"

class Bee : public dr::DynamicObject
{
public:
	void	init() override;
	void	update(sf::Time dt) override;
};