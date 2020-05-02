#include "ScorePresent.h"

ScorePresent::ScorePresent(const sf::Vector2f& position, const sf::Vector2f& size, Board& board)
	:Present(position,size,board)
{}
void ScorePresent::colide(Player& player)
{
	player.increaseScore(SCORE_PRESENT);
	Present::colide(player);
}

