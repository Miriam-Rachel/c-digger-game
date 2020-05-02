#pragma once
#include <SFML/Graphics.hpp>
#include "Resource.h" 
#include "macros.h"

class Player;

class Object
{
public:
	virtual void draw(sf::RenderWindow&)  = 0;
	virtual void colide(Player& player) = 0;
	static sf::Sprite create(const sf::Vector2f& position, const sf::Vector2f& size, int index);
protected:
	
	sf::Sprite scale(const sf::Vector2f& size, sf::Sprite sprite) const;
	
};