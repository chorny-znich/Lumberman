#include "cloud.h"
#include <random>

void Cloud::init()
{
	mSprite.setTexture(dr::Textures::get("Cloud"));
}

void Cloud::update(sf::Time dt)
{
	std::random_device rd;
	std::mt19937 rn(rd());

	if (!mActive)
	{
		mSpeed = static_cast<float>((rn() % 100) + 50);
		float height = static_cast<float>((rand() % 250));
		mSprite.setPosition(-200, height);
		mActive = true;
	}
	else
	{
		mSprite.setPosition(mSprite.getPosition().x + (mSpeed * dt.asSeconds()), mSprite.getPosition().y);

		if (mSprite.getPosition().x > 1920)
		{
			mActive = false;
		}
	}
}

void Cloud::render(sf::RenderWindow& window)
{
	window.draw(mSprite);
}