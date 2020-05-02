#pragma once
#include "DinamicObject.h"

class Player :public DinamicObject
{
public:

	//default c-tor
	Player();

	//recieves all data from file needed for the player in one level
	void initDataForLevel(const sf::Vector2f& position, const sf::Vector2f& size,float limit, int stones = 0, int diamonds = 0);
	
	//recieves an event and manage it
	void handlePress(sf::Keyboard::Key key);

	//drae the player
	virtual void draw(sf::RenderWindow& window)override;

	//return if the player havo more lives
	bool alive() const;

	//reduce by one the num of lives
	void reduceLives();

	//returns if the player ate all diamonds for this level
	bool ateAllDiamonds()const;

	//returns if the player all stones that he enable to
	bool ateAllStones() const;

	//returns if a monster ate the player
	bool hurtedByMonster() const;

	//empty function only to avoid abstraction
	virtual void colide(Player& player)override;

	//increase num of score
	void increaseScore(int amount);

	//reducing by one num of diamonds are left to eat
	void reducingAmountDiamonds();

	//update that the player was hurted by a monster
	void updateCollision();

	//reducing by onr the num of stons that the player is awaylabel to eat
	void reducingAmountStone();

	//increase the num of stons te player can eat( a present)
	void increaseStone();

	//return the time limitation of this level
	float getLimit() const;

	//increase the time limitation
	void timePresent();
//???
	sf::FloatRect getGlobalBounds()const;

	//take the player to the strt position
	void replace();
	int getLives();
	int getStones();
	int getScore();

protected:

	int m_score;
	int m_lives;
	int m_diamondsLeft;
	int m_stonesLeft;
	bool m_hurtedByMonster;
	float m_timeLimit;
	sf::Vector2f m_beforStopDirection;

};