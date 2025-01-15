#pragma once

#include "Lumberman.h"

/**
 * @brief Awaiting while the player press a button before the level starts
*/
class PauseScreen : public dr::Screen
{
private:
	enum class State {START, END};

	State mScreenState;
	sf::Text mMessageText;

public:
	virtual void init() override;
	virtual void inputHandler(sf::Vector2i position, sf::RenderWindow* window) override;
	virtual void inputHandler(sf::Keyboard::Key, bool isPressed) override;
	virtual void inputHandler(sf::Mouse::Button, bool isPressed, sf::Vector2i position, sf::RenderWindow* window) override;
	virtual void update(sf::Time dt) override;
	virtual void render(sf::RenderWindow& window) override;
};