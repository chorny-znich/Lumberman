#include "screen_manager.h"
#include "menu_screen.h"
#include "about_screen.h"
#include "game_screen.h"
#include "pause_screen.h"
#include "record_screen.h"
#include <memory>

void ScreenManager::createScreen(GameData::Screens screenID)
{
	if (screenID == GameData::Screens::MENU) {
		std::unique_ptr<MenuScreen> pMenuScreen = std::make_unique<MenuScreen>();
		pMenuScreen->init();
		dr::GameState::addScreen(std::move(pMenuScreen));
	} 
	else if (screenID == GameData::Screens::ABOUT) {
		std::unique_ptr<AboutScreen> pAboutScreen = std::make_unique<AboutScreen>();
		pAboutScreen->init();
		dr::GameState::addScreen(std::move(pAboutScreen));
	}
	else if (screenID == GameData::Screens::PAUSE)
	{
		std::unique_ptr<PauseScreen> pPauseScreen = std::make_unique<PauseScreen>();
		pPauseScreen->init();
		dr::GameState::addScreen(std::move(pPauseScreen));
	}
	else if (screenID == GameData::Screens::GAME)
	{
		std::unique_ptr<GameScreen> pGameScreen = std::make_unique<GameScreen>();
		pGameScreen->init();
		dr::GameState::addScreen(std::move(pGameScreen));
	}
	else if (screenID == GameData::Screens::RECORD)
	{
		std::unique_ptr<RecordScreen> pRecordScreen = std::make_unique<RecordScreen>();
		pRecordScreen->init();
		dr::GameState::addScreen(std::move(pRecordScreen));
	}
}