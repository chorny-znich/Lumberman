#include "player.h"

Player::Player() : 
	mSide(gd::Side::LEFT),
	mShow(true),
	LEFT_POSITION({ 580.f, 720.f }),
	RIGHT_POSITION({ 1200.f, 720.f })
{
}

void Player::init()
{
	mSprite.setTexture(dr::Textures::get("Player"));
	mAxe.init();
	mGravestone.init();
}

gd::Side Player::update()
{
	if (mSide == gd::Side::LEFT)
	{
		mSprite.setPosition(LEFT_POSITION);
	}
	else if (mSide == gd::Side::RIGHT)
	{
		mSprite.setPosition(RIGHT_POSITION);
	}

	mAxe.update(mSide);

	return mSide;
}

void Player::render(sf::RenderWindow& window)
{
	if (mShow)
	{
		window.draw(mSprite);
	}
	mAxe.render(window);
	mGravestone.render(window);
}

void Player::show(bool isShow)
{
	mShow = isShow;
}

void Player::showAxe(bool show)
{
	mAxe.isShow(show);
}

void Player::showGravestone(bool isShow)
{
	mGravestone.isShow(isShow);
}

void Player::setSide(gd::Side side)
{
	mSide = side;
}
gd::Side Player::getSide() const
{
	return mSide;
}