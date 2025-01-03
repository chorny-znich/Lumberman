#pragma once
#include <vector>
#include "Lumberman.h"

class Level
{
private:
	std::vector<dr::StaticObject> mStaticObjects;
	std::vector<dr::DynamicObject> mDynamicObjects;
};