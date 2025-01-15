#include "bee.h"
#include <random>

void Bee::init()
{
	mSprite.setTexture(dr::Textures::get("Bee"));
}

void Bee::update(sf::Time dt)
{
	std::random_device rd;
	std::mt19937 rn(rd());

	if (!mActive)
	{
		mSpeed = static_cast<float>((rn() % 200) + 200);
		float height = static_cast<float>((rn() % 500) + 500);
		mSprite.setPosition(2000, height);
		mActive = true;

	}
	else
	{
		mSprite.setPosition(mSprite.getPosition().x - (mSpeed * dt.asSeconds()), mSprite.getPosition().y);

		if (mSprite.getPosition().x < -100.f)
		{
			mActive = false;
		}
	}
}