#include "Stone.h"
#include "Board.h"

Stone::Stone( const sf::Vector2f& position, const sf::Vector2f& size,Board& board )
	:StaticObject( position, size,stone),m_board(board)
{}
void Stone::colide(Player& player)
{
	player.reducingAmountStone();
	m_board.deleteCell(sf::Vector2i((m_sprite.getPosition().x - m_sprite.getGlobalBounds().width / 2) / m_sprite.getGlobalBounds().width,
		(m_sprite.getPosition().y - m_sprite.getGlobalBounds().height / 2) / m_sprite.getGlobalBounds().height));
}

void Stone::colide(Monster& monster)
{
	monster.goBack();
}
