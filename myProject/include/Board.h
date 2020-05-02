#pragma once
#include "Player.h"
#include "Diamond.h"
#include "RegularMonster.h"
#include "ScorePresent.h"
#include "SmartMonster.h"
#include "Stone.h"
#include "StonesPresent.h"
#include "TimePresent.h"
#include "Wall.h"
#include <fstream>


class Level;

class Board
{
public:
	//c-tor
	Board(Player& player, Level& level,const std::string fileName);

	//copy c-tor
	Board(const Board&) = delete;

	//assign operator
	Board& operator=(const Board&) = delete;
	
	//draw the whol board
	void draw(sf::RenderWindow& window) ;

	
	
	StaticObject* getContentOf(const sf::Vector2i& cell) const;
	void deleteCell(const sf::Vector2i& cell );
	~Board();
protected:

	//add a present to the matrix vector by random a type of present
	void addPresent(sf::Vector2f position, sf::Vector2f size,int row,Board& board);

	//recieves indexes and convert them to pixels on the screen 
	sf::Vector2f indexToPixel(int row, int col);

	void readFile(Player& player, Level& level);
	std::vector < std::vector<StaticObject*> > m_statics;
	std::ifstream m_file; 
	int m_cols;
	int m_rows;
	sf::Sprite m_sprite;      
};