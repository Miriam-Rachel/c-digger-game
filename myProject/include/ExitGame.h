#pragma once
#include "macros.h"
#include "Button.h"

class ExitGame : public Button
{
public:
	ExitGame(int ExitGame);
	virtual bool handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window);
	virtual void drawOnWindow(sf::RenderWindow& window);
	virtual ~ExitGame() = default;
protected:

};