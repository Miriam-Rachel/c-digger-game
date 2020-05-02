#pragma once
#include "Board.h"
#include "Monster.h"
#include "Info.h"


class Level
{
public:

	//c-tor
	Level(Player& player,const std::string fileName);

	//copy c-tor
	Level(const Player&) = delete;

	Player& operator=(const Player&) = delete;

	//random a monster type and add it to the monsters vector
	void addMonster(const sf::Vector2f& position, const sf::Vector2f& size,Player& player);

	//run one level
	bool run(bool& haveToRestart, sf::RenderWindow& window,int numOfLevel);

	//recieves events and do things accordingly
	void manageEvents(sf::RenderWindow& window);

	//check if the time for the level is over
	bool timeOut() const;

	~Level();

protected:

	std::vector<Monster*> m_monsters;
	Board m_board;
	sf::Clock m_clockOfMoving;
	sf::Clock m_clockOfLevel;
	Player& m_player;

	//move all
	void move();

	//draw all
    void draw(sf::RenderWindow& window); 

	//replace all in case of a monster colide the player
	void replace();

	// check if there is colisions and do the right things
	void checkCollision();
};//039629669
