#pragma once
#include "macros.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class NewGame :public Button
{
public:
	NewGame(int NewGame);
	virtual bool handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window);
	virtual void drawOnWindow(sf::RenderWindow& window);
	virtual ~NewGame() = default;
private:

};