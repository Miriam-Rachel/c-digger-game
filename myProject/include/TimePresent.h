#pragma once
#include "Present.h"

class Level;
class TimePresent :public Present
{
public:
	TimePresent(const sf::Vector2f& position, const sf::Vector2f& size,Board& board);
	virtual void colide(Player& player)override;
};