#include "StaticObject.h"

StaticObject::StaticObject( const sf::Vector2f& position, const sf::Vector2f& size, int index)
	:m_sprite(create(position,size,index))
{}

void StaticObject::draw(sf::RenderWindow& window) 
{
	window.draw(m_sprite);
}
