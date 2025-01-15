//=================================================================================================
//	Tree object with branches																	===
//=================================================================================================

#pragma once

#include <array>
#include "Lumberman.h"
#include "branch.h"
#include "wood_log.h"

class Tree
{
private:
	std::array<Branch, gd::NUM_BRANCHES> mBranches;
	WoodLog					mWoodLog;

	bool					mNeedUpdate;

public:
	Tree();
	void init();
	gd::Side update(sf::Time dt);
	void render(sf::RenderWindow& window);

	void					spawn();

	void					isNeedUpdate(gd::Side side);
};