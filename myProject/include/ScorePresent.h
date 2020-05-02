#pragma once
#include "Present.h"

class ScorePresent :public Present
{
public:
	ScorePresent(const sf::Vector2f& position, const sf::Vector2f& size,  Board& board);
	virtual void colide(Player& player)override;
};