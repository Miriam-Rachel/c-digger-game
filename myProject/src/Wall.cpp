#include "Wall.h"

Wall::Wall(const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObject(position,size,wall)
{}

void Wall::colide(Player& player)
{
	player.goBack();
	/*Board::deleteCell(player.m_position.x, player.m_position.y);*/
}

void Wall::colide(Monster& monster)
{
	monster.goBack();
}