#include "Present.h"
#include "Board.h"

Present::Present( const sf::Vector2f& position, const sf::Vector2f& size, Board& board)
	:StaticObject( position, size, present), m_board(board)
{}

void Present::colide(Monster & monster)
{}

void Present::colide(Player & player)
{
	m_board.deleteCell(sf::Vector2i((m_sprite.getPosition().x - m_sprite.getGlobalBounds().width / 2) / m_sprite.getGlobalBounds().width,
		(m_sprite.getPosition().y - m_sprite.getGlobalBounds().height / 2) / m_sprite.getGlobalBounds().height));
//להכניס לפונ שממירה מיקום לקואורדינטת
}
