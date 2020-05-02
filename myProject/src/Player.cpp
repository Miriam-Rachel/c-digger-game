#include "Player.h"
#include <iostream>

//c-tor
Player::Player():DinamicObject(sf::Vector2f(100,100),sf::Vector2f(1,1),Diver1,TEXTURES_FOR_PLAYER),
m_lives(NUM_OF_LIVES),m_score(0),m_hurtedByMonster(false)
{}

//recieves from file all data needed for one level
void Player::initDataForLevel(const sf::Vector2f& position, const sf::Vector2f& size, float limit,int stones, int diamonds)
{
	for (int index = 0; index < TEXTURES_FOR_PLAYER; index++)//resize and put on te right position
		m_sprites[index] = create(position,size,index+2);
	m_direction = sf::Vector2f(1,0);//right is the default direction
	m_hurtedByMonster = false;
	m_nxtDirection = Right;
	m_prevPosition = m_strtPosition = position;
	m_stonesLeft = stones;
	m_diamondsLeft = diamonds;
	m_timeLimit = limit;
}


// manage events that are related with the player
void Player::handlePress(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Space)
	{
		m_beforStopDirection = m_direction;
		m_direction = sf::Vector2f(0, 0);//stoping
		m_nxtDirection = nothing;
	}
	else
	{
		m_nxtDirection = Utilities::keyToDirection(key);
		if(m_direction == sf::Vector2f(0,0))
		m_direction = m_beforStopDirection;
	}
}

	
void Player::draw(sf::RenderWindow & window) //override
{
	DinamicObject::draw(window);//draw all sprites
	m_spriteIndex %= TEXTURES_FOR_PLAYER;
}

bool Player::alive() const
{
	return m_lives > 0;
}

void Player::reduceLives()
{
	m_lives--;
}

bool Player::ateAllDiamonds() const
{
	return m_diamondsLeft == 0;
}

bool Player::ateAllStones() const
{
	return m_stonesLeft == 0;
}

bool Player::hurtedByMonster() const
{
	return m_hurtedByMonster;
}

void Player::colide(Player& player)
{}

void Player::increaseScore(int amount)
{
	m_score += amount;
}

void Player::reducingAmountDiamonds()
{
	m_diamondsLeft--;
}

void Player::updateCollision()
{
	m_hurtedByMonster = true;
}

void Player::reducingAmountStone()
{
	m_stonesLeft--;
}



void Player::increaseStone()
{
	m_stonesLeft += SCORE_PRESENT;
}

float Player::getLimit() const
{
	return m_timeLimit;
}

void Player::timePresent()
{
	m_timeLimit += TIME_PRESENT;
}

sf::FloatRect Player::getGlobalBounds() const
{
	return m_sprites[0].getGlobalBounds();
}

void Player::replace()
{
	DinamicObject::replace();
	m_hurtedByMonster = false;
}

int Player::getLives()
{
	return m_lives;
}

int Player::getStones()
{
	return m_stonesLeft;
}

int Player::getScore()
{
	return m_score;
}



