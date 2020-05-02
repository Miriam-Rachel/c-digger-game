#pragma once
#include "Monster.h"

class RegularMonster :public Monster
{
public:
	RegularMonster(const sf::Vector2f& position, const sf::Vector2f& size);
	virtual void draw(sf::RenderWindow& window)override;
	virtual void move(const sf::Time& deltaTim)override;
	void goBack();
	virtual ~RegularMonster() = default;
protected:
}; 