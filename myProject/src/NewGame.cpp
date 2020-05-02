#include"NewGame.h"
#include <iostream>
//---------------------------------------------------------------------------------
NewGame::NewGame(int NewGame) :Button(NewGame1, sf::Vector2f{ (WIDTH_OF_WINDOW / 2) - (2.5 * HEIGHT_OF_BUTTON) ,(HEIGHT_OF_WINDOW / 2) - (HEIGHT_OF_BUTTON) })
{

}
bool NewGame::handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	if (Button::isContain(event, window))
		return true;
	return false;
}
//----------------------------------------------------------------------------------
void NewGame::drawOnWindow(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}