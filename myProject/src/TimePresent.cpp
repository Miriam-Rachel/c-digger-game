#include "TimePresent.h"
#include "Level.h"

TimePresent::TimePresent(const sf::Vector2f& position, const sf::Vector2f& size, Board& board)
	:Present(position, size,board)
{}
void TimePresent::colide(Player& player)
{
	player.timePresent();
	Present::colide(player);
}
