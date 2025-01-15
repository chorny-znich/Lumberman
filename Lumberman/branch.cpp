#include "branch.h"

Branch::Branch() : 
	mSide(gd::Side::NONE)
{}

void Branch::init()
{
	mSprite.setTexture(dr::Textures::get("Branch"));
	mSprite.setPosition(-2000.f, -2000.f);
	mSprite.setOrigin(220.f, 20.f);
}

void Branch::render(sf::RenderWindow& window)
{
	window.draw(mSprite);
}

sf::Sprite& Branch::getSprite()
{
	return mSprite;
}

void Branch::setSide(gd::Side side)
{
	mSide = side;
}
gd::Side Branch::getSide() const
{
	return mSide;
}