#include "game.h"
#include <iostream>
#include <string>

//	Инициализация ресурсов
void Game::init()
{
	try
	{
		dr::Textures::init("data/texture_list.txt");
		dr::Sounds::init("data/sound_list.txt");
	}
	catch (const std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}

	dr::Fonts::load("Main", "assets/font/brushtype.ttf");

	sf::Text mGameTitleText;
	sf::Text mPauseMessageText;
	sf::Text mScoreText;
	sf::Text mLevelNumberText;
	sf::Text mDefeatText;
	sf::Text mTimeEndText;
	sf::Text mSmashText;
	sf::Text mRecordText;

	mGameTitleText.setFont(dr::Fonts::get("Main"));
	mPauseMessageText.setFont(dr::Fonts::get("Main"));
	mScoreText.setFont(dr::Fonts::get("Main"));
	mLevelNumberText.setFont(dr::Fonts::get("Main"));
	mDefeatText.setFont(dr::Fonts::get("Main"));
	mTimeEndText.setFont(dr::Fonts::get("Main"));
	mSmashText.setFont(dr::Fonts::get("Main"));
	mRecordText.setFont(dr::Fonts::get("Main"));

	mGameTitleText.setString("ЛЕСОРУБ");
	mPauseMessageText.setString("Нажмите 'Enter' для начала игры!");
	mScoreText.setString("Очки : 0");
	mLevelNumberText.setString("Уровень : 1");
	mDefeatText.setString("Вы набрали 0 очков");
	mTimeEndText.setString("Время закончилось!!");
	mSmashText.setString("Раздавило!!");
	mRecordText.setString("0");

	mGameTitleText.setCharacterSize(225);
	mPauseMessageText.setCharacterSize(75);
	mScoreText.setCharacterSize(50);
	mLevelNumberText.setCharacterSize(50);
	mDefeatText.setCharacterSize(75);
	mTimeEndText.setCharacterSize(75);
	mSmashText.setCharacterSize(75);
	mRecordText.setCharacterSize(75);

	mGameTitleText.setFillColor(sf::Color(40, 26, 13));
	mPauseMessageText.setFillColor(sf::Color(40, 26, 13));
	mScoreText.setFillColor(sf::Color::White);
	mLevelNumberText.setFillColor(sf::Color::White);
	mDefeatText.setFillColor(sf::Color(40, 26, 13));
	mTimeEndText.setFillColor(sf::Color::White);
	mSmashText.setFillColor(sf::Color::White);
	mRecordText.setFillColor(sf::Color::White);

	sf::FloatRect textRect = mPauseMessageText.getLocalBounds();
	sf::FloatRect textRect2 = mDefeatText.getLocalBounds();
	sf::FloatRect textRect3 = mTimeEndText.getLocalBounds();
	sf::FloatRect textRect4 = mSmashText.getLocalBounds();

	mGameTitleText.setPosition({ 30.f, 90.f });
	mPauseMessageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	mPauseMessageText.setPosition(gd::GAME_RESOLUTION.x / 2.0f, gd::GAME_RESOLUTION.y / 2.0f);
	mScoreText.setPosition(20, 60);
	mLevelNumberText.setPosition({ 20.f, 5.f });
	mDefeatText.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);
	mDefeatText.setPosition(gd::GAME_RESOLUTION.x / 2.0f, gd::GAME_RESOLUTION.y / 2.0f);
	mTimeEndText.setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top + textRect3.height / 2.0f);
	mTimeEndText.setPosition(gd::GAME_RESOLUTION.x / 2.0f, gd::GAME_RESOLUTION.y / 2.0f);
	mSmashText.setOrigin(textRect4.left + textRect4.width / 2.0f, textRect4.top + textRect4.height / 2.0f);
	mSmashText.setPosition(gd::GAME_RESOLUTION.x / 2.0f, gd::GAME_RESOLUTION.y / 2.0f);

	dr::TextManager::load("Title", mGameTitleText);
	dr::TextManager::load("PauseMessage", mPauseMessageText);
	dr::TextManager::load("Score", mScoreText);
	dr::TextManager::load("Level", mLevelNumberText);
	dr::TextManager::load("DefeatMessage", mDefeatText);
	dr::TextManager::load("TimeEnd", mTimeEndText);
	dr::TextManager::load("Smash", mSmashText);
	dr::TextManager::load("RecordValue", mRecordText);

	AudioPlayer::init();
}