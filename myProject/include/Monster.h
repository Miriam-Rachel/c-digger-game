#pragma once
#include "DinamicObject.h"

class Monster :public DinamicObject
{
public:
	Monster(const sf::Vector2f& position, const sf::Vector2f& size, int firstTexture, int numOfTextures);
	virtual void move(const sf::Time& deltaTime) override = 0;
	virtual void colide(Player& player)override;
	virtual ~Monster() = default;
protected:
};