#include "axe.h"
#include <iostream>

Axe::Axe() : 
	mSide(gd::Side::NONE), 
	mShow(false),
	LEFT_POSITION({ 700.f, 830.f }), 
	RIGHT_POSITION({ 1075.f, 830.f })
{}

void Axe::init()
{
	mSprite.setTexture(dr::Textures::get("Axe"));
}

void Axe::update(gd::Side side)
{
	if (mShow)
	{
		if (side == gd::Side::LEFT)
		{
			mSprite.setPosition(LEFT_POSITION);
		}
		else if (side == gd::Side::RIGHT)
		{
			mSprite.setPosition(RIGHT_POSITION);
		}
	}
}

void Axe::render(sf::RenderWindow& window)
{
	if (mShow)
	{
		window.draw(mSprite);
	}
}

void Axe::isShow(bool show)
{
	mShow = show;
}

void Axe::setSide(gd::Side side)
{
	mSide = side;
}