#pragma once
#include "StaticObject.h"

class Board;

class Diamond :public StaticObject
{
public:
	Diamond(const sf::Vector2f& position, const sf::Vector2f& size, Board& board);
	virtual void colide(Player& player)override;
	virtual void colide(Monster& monster)override;
protected:
	Board& m_board;
};