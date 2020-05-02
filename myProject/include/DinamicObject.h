#pragma once
#include "Object.h"
#include <vector>
#include "macros.h"
#include "Utilities.h"


class DinamicObject :public Object
{
public:

	DinamicObject(const sf::Vector2f& position, const sf::Vector2f& size, int firstTexture, int numOfTextures);
	DinamicObject() = default;
	virtual void draw(sf::RenderWindow& window);
	virtual void move(const sf::Time& deltaTime) ;
	sf::Vector2f getPosition() const;
	void replace();
	sf::Vector2i collisionCell() const;
	virtual void goBack();
	void checkBoarder();
	sf::Vector2f collisionPoint() const;
protected:
	std::vector<sf::Sprite> m_sprites;
	// couse we want draw few sprites for an object
	int m_spriteIndex = 0;
    sf::Vector2f m_strtPosition;
	sf::Vector2f m_direction = { 0,0 };
	sf::Vector2f m_prevPosition;
	int m_numOfSteps = 0;
	Directions m_nxtDirection = Right;
	sf::Vector2f m_strtDirection;

	//rotate all sprites in m_sprites
	void setRotation(float angle);

	//שקוף all sprites of m_sprites
	void transform(Directions direction);

	//
	

	

	bool matrixMatching();
	bool rotating() const;
	Directions vectorToDirection()const;
	
};
