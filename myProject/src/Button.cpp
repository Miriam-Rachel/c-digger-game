#include "Button.h"

Button::Button(int name, const sf::Vector2f& position) :m_sprite(*Resource::getInstance()[name])
{
	m_sprite.setPosition(position);
}
//--------------------------------------------------------
void Button::drawOnWindow(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

bool Button::isContain(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	if (m_sprite.getGlobalBounds().contains(
		window.mapPixelToCoords({ event.x, event.y })))
		return true;
	return false;
}