#include "wood_log.h"

WoodLog::WoodLog() : DynamicObject(), mSpeed(1000.f, -1500.f)
{}

void WoodLog::init()
{
	mSprite.setTexture(dr::Textures::get("WoodLog"));
	mSprite.setPosition({ 810.f, 720.f });
}

void WoodLog::update(sf::Time dt) 
{
	if (mActive)
	{
		mSprite.setPosition(mSprite.getPosition().x + (mSpeed.x * dt.asSeconds()), mSprite.getPosition().y + (mSpeed.y * dt.asSeconds()));

		if (mSprite.getPosition().x < -100 || mSprite.getPosition().x > 2000)
		{
			mActive = false;
			mSprite.setPosition(810.0f, 720.f);
		}
	}
}

void WoodLog::move(gd::Side side)
{
	if (side == gd::Side::RIGHT)
	{
		mSprite.setPosition({ 810.f, 720.f });
		mActive = true;
		mSpeed = {-5000.f, mSpeed.y};
	}
	else
	{
		mSprite.setPosition({ 810.f, 720.f });
		mActive = true;
		mSpeed = { 5000.f, mSpeed.y };
	}
}