#include "gravestone.h"

void Gravestone::init()
{
	mSprite.setTexture(dr::Textures::get("Gravestone"));
	mSprite.setPosition(POSITION);
}

void Gravestone::render(sf::RenderWindow& window)
{
	if (mShow)
	{
		window.draw(mSprite);
	}
}

void Gravestone::isShow(bool show)
{
	mShow = show;
}