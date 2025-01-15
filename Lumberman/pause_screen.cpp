#include "pause_screen.h"
#include "game_stats.h"
#include "screen_manager.h"
#include <sstream>

void PauseScreen::init()
{
	mBackground.setTexture(dr::Textures::get("PauseBackground"));
	mMessageText = dr::TextManager::get("PauseMessage");
	mScreenState = State::START;
}

void PauseScreen::inputHandler(sf::Vector2i position, sf::RenderWindow* window)
{
}

void PauseScreen::inputHandler(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Return && isPressed)
	{
		if (mScreenState == State::START)
		{
			mScreenState = State::END;
			ScreenManager::createScreen(GameData::Screens::GAME);
		}
		else
		{
			dr::GameState::destroyScreen();
			GameStats::checkRecords();
			GameStats::reset();
		}
	}
}

void PauseScreen::inputHandler(sf::Mouse::Button, bool isPressed, sf::Vector2i position, sf::RenderWindow* window)
{}

void PauseScreen::update(sf::Time dt)
{
	if (mScreenState == State::START)
	{
		mMessageText = dr::TextManager::get("PauseMessage");
	}
	else
	{
		mMessageText = dr::TextManager::get("DefeatMessage");
		std::stringstream ss;
		ss << "Вы получили " << GameStats::getScore() << " очков";
		mMessageText.setString(ss.str());
	}
}

void PauseScreen::render(sf::RenderWindow& window)
{
	window.draw(mBackground);
	window.draw(mMessageText);
}