#include "Diamond.h"
#include "Board.h"

Diamond::Diamond( const sf::Vector2f& position, const sf::Vector2f& size, Board& board)
	:StaticObject( position, size, Pearl), m_board(board)
{}
void Diamond::colide(Player& player)
{
	player.increaseScore(SCORE_OF_DIAMOND);
	player.reducingAmountDiamonds();
	m_board.deleteCell(sf::Vector2i((m_sprite.getPosition().x - m_sprite.getGlobalBounds().width / 2) / m_sprite.getGlobalBounds().width,
		(m_sprite.getPosition().y - m_sprite.getGlobalBounds().height / 2) / m_sprite.getGlobalBounds().height));
}

void Diamond::colide(Monster& monster)
{}