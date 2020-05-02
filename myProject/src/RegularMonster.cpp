#include "RegularMonster.h"
#include <iostream>

RegularMonster::RegularMonster(const sf::Vector2f& position, const sf::Vector2f& size)
	:Monster(position,size,Shark1,TEXTURES_FOR_MONSTER)
{}

void RegularMonster::draw(sf::RenderWindow & window)
{
	DinamicObject::draw(window);
	m_spriteIndex %= TEXTURES_FOR_MONSTER;
}

void RegularMonster::move(const sf::Time& deltaTime)
{
	m_numOfSteps++;
	if (m_numOfSteps == MAX_STEPS_FOR_DIRECTION) { //we would like to change direction once in 10 iteratinos 
		m_nxtDirection = Directions(rand() % NUM_OF_DIRECTIONS);
		m_numOfSteps = 0;
	}
	DinamicObject::move(deltaTime);
}

void RegularMonster::goBack()
{
	DinamicObject::goBack();
	m_numOfSteps = MAX_STEPS_FOR_DIRECTION-1;//we want him to random a new direction immieditly
}


