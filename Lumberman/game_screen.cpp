#include "game_screen.h"
#include "audio_player.h"
#include "game_stats.h"
//#include <iostream>

GameScreen::GameScreen() : 
	mMainView(gd::GAME_VIEW),
	/*mLevelNumber(1),*/
	mTimeRemaining(6.f),
	mAcceptInput(true),
	mPlaying(true)
{
	mTree.spawn();
}

void GameScreen::init()
{
	mBackground.setTexture(dr::Textures::get("GameBackground"));
	mTreeSprite.setTexture(dr::Textures::get("Tree"));
	mTreeSprite.setPosition(TREE_POSITION);
	mBee.init();
		
	for (auto& cloud : mClouds)
	{
		cloud.init();
	}

	mPlayer.init();
	mTree.init();
	mGui.init();
}

void GameScreen::inputHandler(sf::Vector2i position, sf::RenderWindow* window)
{
}

void GameScreen::inputHandler(sf::Keyboard::Key key, bool isPressed)
{
	if (mPlaying)
	{
		if (!isPressed)
		{
			mAcceptInput = true;
			mPlayer.showAxe(false);
		}

		if (mAcceptInput)
		{
			if (key == sf::Keyboard::Right && isPressed)
			{
				mPlayer.setSide(gd::Side::RIGHT);
				mPlayer.showAxe(true);
				AudioPlayer::play("Chop");
				GameStats::increaseScore();
				mTimeRemaining += static_cast<float>(2 / GameStats::getScore()) + .15;

				mTree.isNeedUpdate(gd::Side::RIGHT);

				mAcceptInput = false;
			}

			if (key == sf::Keyboard::Left && isPressed)
			{
				mPlayer.setSide(gd::Side::LEFT);
				mPlayer.showAxe(true);
				AudioPlayer::play("Chop");
				GameStats::increaseScore();

				mTimeRemaining += static_cast<float>(2 / GameStats::getScore()) + .15;

				mTree.isNeedUpdate(gd::Side::LEFT);

				mAcceptInput = false;
			}
		}
	}
	else
	{
		if (key == sf::Keyboard::Return && isPressed)
		{
			dr::GameState::destroyScreen();
		}
	}
}

void GameScreen::inputHandler(sf::Mouse::Button button, bool isPressed, sf::Vector2i position,
	sf::RenderWindow* window)
{}

void GameScreen::update(sf::Time dt)
{	
	if (mPlaying)
	{
	mBee.update(dt);
	
	for (auto& cloud : mClouds)
	{
		cloud.update(dt);
	}

	mTimeRemaining -= dt.asSeconds();
	if (mTimeRemaining <= 0.0f)
	{
		mMessageText = dr::TextManager::get("TimeEnd");

		AudioPlayer::play("OutOfTime");
		mPlaying = false;
	}

	mPlayer.update();
	mTree.update(dt);
	checkCollision(mPlayer.update(), mTree.update(dt));
	mGui.update(mTimeRemaining);
	}
}

void GameScreen::render(sf::RenderWindow& window)
{
	window.setView(mMainView);
	window.draw(mBackground);

	for (auto& cloud : mClouds)
	{
		cloud.render(window);
	}

	window.draw(mTreeSprite);

	mBee.render(window);
	
	mPlayer.render(window);
	mTree.render(window);
	mGui.render(window);

	if (!mPlaying)
	{
		window.draw(mMessageText);
	}
}

//	Checking collision with a branch
void GameScreen::checkCollision(gd::Side player, gd::Side branch)
{
	if (branch == player)
	{
		mPlaying = false;
		mAcceptInput = false;
		mPlayer.show(false);
		mPlayer.showAxe(false);
		mPlayer.showGravestone(true);
		mGui.isShowTimebar(false);

		mMessageText = dr::TextManager::get("Smash");
		AudioPlayer::play("Death");
		mPlaying = false;
//		GameStats::checkRecords();
	}
}
/*
void GameScreen::startLevel()
{
	mTimeRemaining = 6.f;

	mTree.spawn();
}
/*
void Level::setLevelNumber(size_t number)
{
	mLevelNumber = number;
}
size_t Level::getLevelNumber() const
{
	return mLevelNumber;
}*/