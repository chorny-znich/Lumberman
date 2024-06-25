//=================================================================================================
//	Pause screen																				===
//	Awaiting button press before level start													===
//=================================================================================================

#pragma once

#include "Lumberman.h"

class PauseScreen : public dr::Screen
{
private:
	enum class State {START, END};

	State mScreenState;
	sf::Text mMessageText;

public:
	virtual void init() override;
	virtual void inputHandler(sf::Keyboard::Key, bool isPressed) override;
	virtual void inputHandler(sf::Mouse::Button, bool isPressed, sf::Vector2i position) override;
	virtual void update(sf::Time dt) override;
	virtual void render(sf::RenderWindow& window) override;
};