#include "StonesPresent.h"

StonesPresent::StonesPresent(const sf::Vector2f& position, const sf::Vector2f& size, Board& board)
	:Present(position,size,board)
{}
void StonesPresent::colide(Player& player)
{
	player.increaseStone();
	Present::colide(player);
}
