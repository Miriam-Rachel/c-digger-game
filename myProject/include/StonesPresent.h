#pragma once
#include "Present.h"

class StonesPresent : public Present
{
public:
	StonesPresent(const sf::Vector2f& position, const sf::Vector2f& size, Board& board);
	virtual void colide(Player& player)override;
};