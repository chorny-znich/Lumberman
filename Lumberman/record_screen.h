#pragma once

#include <array>
#include "Lumberman.h"

/**
 * @brief Show list of 5 best result
*/
class RecordScreen : public dr::Screen
{
private:
	static const size_t	NUM_RECORD_STRINGS = 5;
	std::array<sf::Sprite, NUM_RECORD_STRINGS>	mPlaces; // Background for results
	std::array<sf::Text, NUM_RECORD_STRINGS> mRecordText; // Results as sf::Text objects

public:
	void init() override;
	virtual void inputHandler(sf::Vector2i position, sf::RenderWindow* window) override;
	void inputHandler(sf::Keyboard::Key, bool isPressed) override;
	void inputHandler(sf::Mouse::Button, bool isPressed, sf::Vector2i position, sf::RenderWindow* window) override;
	void update(sf::Time dt) override;
	void render(sf::RenderWindow& window) override;

/*	virtual std::string				getState() override;
	virtual bool					changeState() override;
	virtual void					resetState() override;
*/
//	void							updateRecords();
};