














#include "ExitGame.h"
//---------------------------------------------------------------
ExitGame::ExitGame(int ExitGame) :Button(ExitGame, sf::Vector2f{ (WIDTH_OF_WINDOW / 2) - (2.5 * HEIGHT_OF_BUTTON) ,(HEIGHT_OF_WINDOW / 2) + (HEIGHT_OF_BUTTON) })
{ //
}
//-------------------------------------------------------------
bool ExitGame::handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	if (Button::isContain(event, window))
	{
		exit(0);
		return true;
	}
	return false;
}
//-------------------------------------------------------------
void ExitGame::drawOnWindow(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}