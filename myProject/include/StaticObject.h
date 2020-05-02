#pragma once
#include "Object.h"
#include "SmartMonster.h"
#include "RegularMonster.h"

class StaticObject:public Object
{
public:
	StaticObject( const sf::Vector2f& position, const sf::Vector2f& size, int index);
	virtual void draw(sf::RenderWindow& window) ;
	virtual void colide(Monster& monster) = 0;
	virtual void colide(Player& player) = 0;
	virtual ~StaticObject() = default;
protected:
	sf::Sprite m_sprite;
};