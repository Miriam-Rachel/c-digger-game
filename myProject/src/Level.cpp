#include "Level.h"

//c-tor
Level::Level(Player& player, const std::string fileName):m_board(player,*this,fileName),m_player(player)
{}

//add a rondomized type of monster to the monsters vector
void Level::addMonster(const sf::Vector2f& position, const sf::Vector2f& size,Player& player)
{
	int monsterType = rand() % 2;
	if (monsterType == SMART_MONSTER)
		m_monsters.push_back(new (std::nothrow) SmartMonster(position, size,player,m_board));
	else
		m_monsters.push_back(new (std::nothrow) RegularMonster(position, size));
}

//run one level
bool Level::run(bool& haveToRestart, sf::RenderWindow& window,int numOfLevel)
{
	Resource::getInstance().m_music.play();
		while (!m_player.ateAllDiamonds())
		{
			window.clear();
			Info::getInstance().displayInformation(m_player.getLives(), m_player.getStones(), m_player.getScore(), numOfLevel, m_player.getLimit() - (m_clockOfLevel.getElapsedTime().asSeconds()), window);
			move();
			checkCollision();
			draw(window);
			window.display();
			manageEvents(window);
		if (m_player.hurtedByMonster())  
			replace();
	    if (m_player.ateAllStones() || timeOut()) 
			{
			haveToRestart = true; m_player.reduceLives(); break;
			}
	    if (!m_player.alive())
		    break;
		}
		Resource::getInstance().m_music.stop();
		return m_player.alive();
}


//draw all
void Level::draw(sf::RenderWindow& window) 
{
	m_board.draw(window);
	for (auto monster : m_monsters)
		monster->draw(window);
	m_player.draw(window);
}


//replace all in case of monster eat te player
void Level::replace()
{
	m_player.replace();
	for (auto monster : m_monsters)
		monster->replace();
}


//recieves events and manage them
void Level::manageEvents( sf::RenderWindow& window)
{
	for (auto event = sf::Event{}; window.pollEvent(event);)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
			break;
		case sf::Event::KeyPressed:
			m_player.handlePress(event.key.code);
			break;
		}
	}
}


//return if the time for tis level is over
bool Level::timeOut() const
{
	if (m_player.getLimit() == NO_LIMIT)
		return false;
	return( int(m_player.getLimit()) -int(m_clockOfLevel.getElapsedTime().asSeconds())==0);
}

Level::~Level()
{
	for (auto monster : m_monsters)
		delete monster;
}


//check if there was collisions and manage them
void Level::checkCollision()
{
   auto obj = m_board.getContentOf(m_player.collisionCell()); //get the object pointed by the cell in matrix the player meet
   if (obj)                                                   //non empty cell
		obj->colide(m_player);
	for (auto monster : m_monsters)
	{

		monster->colide(m_player);
		obj = m_board.getContentOf(monster->collisionCell());
		if (obj)
			obj->colide(*monster);
    }
}


void Level::move()
{
	auto deltaTime = m_clockOfMoving.restart();
	for (auto& monster : m_monsters)
			monster->move(deltaTime);
	m_player.move(deltaTime);
}

