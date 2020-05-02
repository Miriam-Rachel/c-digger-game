#pragma once
#include "StaticObject.h"

class Board;

class Present :public StaticObject
{
public:
	Present(const sf::Vector2f& position, const sf::Vector2f& size, Board& board);
	virtual void colide(Monster& monster)override;
	virtual void colide(Player& player)=0 ;
	virtual ~Present() = default;
protected:
	Board& m_board;
};