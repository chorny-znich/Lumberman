#include "tree.h"
#include <random>

Tree::Tree() :
	mNeedUpdate(false)
{}

void Tree::init()
{
	for (auto& branch : mBranches)
	{
		branch.init();
	}

	mWoodLog.init();
}

gd::Side Tree::update(sf::Time dt)
{
	if (mNeedUpdate)
	{
		//	Move one position down, create the new branch

		for (int j = gd::NUM_BRANCHES - 1; j > 0; j--)
		{
			mBranches[j].setSide(mBranches[j - 1].getSide());
		}

		std::random_device rd;
		std::mt19937 rn(rd());
		int r = (rn() % 5);

		switch (r)
		{
		case 0:
			mBranches[0].setSide(gd::Side::LEFT);
			break;

		case 1:
			mBranches[0].setSide(gd::Side::RIGHT);
			break;

		default:
			mBranches[0].setSide(gd::Side::NONE);
			break;
		}

		mNeedUpdate = false;
	}

	//	Branches position
	for (size_t i = 0; i < gd::NUM_BRANCHES; i++)
	{
		float height = i * 150.f;

		if (mBranches[i].getSide() == gd::Side::LEFT)
		{
			mBranches[i].getSprite().setPosition(610, height);
			mBranches[i].getSprite().setOrigin(220, 40);
			mBranches[i].getSprite().setRotation(180);
		}
		else if (mBranches[i].getSide() == gd::Side::RIGHT)
		{
			mBranches[i].getSprite().setPosition(1330, height);
			mBranches[i].getSprite().setOrigin(220, 40);
			mBranches[i].getSprite().setRotation(0);
		}
		else
		{
			mBranches[i].getSprite().setPosition(3000, height);
		}
	}

	mWoodLog.update(dt);
	
	return mBranches[5].getSide();
}

void Tree::render(sf::RenderWindow& window)
{
	for (auto& branch : mBranches)
	{
		window.draw(branch.getSprite());
	}

	mWoodLog.render(window);
}

void Tree::spawn()
{
	for (auto& branch : mBranches)
	{
		branch.setSide(gd::Side::NONE);
	}
}

void Tree::isNeedUpdate(gd::Side side)
{
	mNeedUpdate = true;
	mWoodLog.move(side);
}