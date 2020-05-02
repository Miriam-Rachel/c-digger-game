#pragma once
#include "StaticObject.h"

class Wall :public StaticObject
{
public:
	Wall( const sf::Vector2f& position, const sf::Vector2f& size);
	virtual void colide(Player& player)override;
	virtual void colide(Monster& monster)override;
	virtual ~Wall() = default;
};