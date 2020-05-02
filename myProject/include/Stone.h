#pragma once
#include "StaticObject.h"

class Board;
class Stone : public StaticObject
{
public:
	Stone( const sf::Vector2f& position, const sf::Vector2f& size, Board& board);
	virtual void colide(Player& player)override;
	virtual void colide(Monster& monster)override;
	virtual ~Stone() = default;
protected:
	Board& m_board;
};