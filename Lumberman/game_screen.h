//=================================================================================================
//	Game screen																					===
//=================================================================================================

#pragma once

#include "Lumberman.h"
#include "bee.h"
#include "cloud.h"
#include "gui.h"
#include "player.h"
#include "tree.h"

#include <array>
#include <vector>

class GameScreen : public dr::Screen 
{
private:
	sf::Sprite mBackground;
	std::vector<dr::StaticObject> mStaticObjects;
	sf::View mMainView;
	sf::Sprite	mTreeSprite;
	Bee mBee;
	std::array<Cloud, gd::NUM_CLOUDS> mClouds;
	Player mPlayer;
	Tree mTree;
	Gui	mGui;

	sf::Text mMessageText;

	const sf::Vector2f	TREE_POSITION{ 810.f, 0.f };
//	size_t					mLevelNumber;
	float mTimeRemaining;
	bool mAcceptInput; // if true, ready to handle player's input
	bool mPlaying;

public:
	GameScreen();

	virtual void init() override;
	virtual void inputHandler(sf::Vector2i position, sf::RenderWindow* window) override;
	virtual void inputHandler(sf::Keyboard::Key, bool isPressed) override;
	virtual void inputHandler(sf::Mouse::Button, bool isPressed, sf::Vector2i position, 
		sf::RenderWindow* window) override;
	virtual void update(sf::Time dt) override;
	virtual void render(sf::RenderWindow& window) override;

	void checkCollision(gd::Side player, gd::Side branch);
	
//	void					startLevel();
/*
	void					setLevelNumber(size_t number);
	size_t					getLevelNumber() const;
*/
};