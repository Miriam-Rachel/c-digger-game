#include "SmartMonster.h"
#include "Board.h"

SmartMonster::SmartMonster( const sf::Vector2f& position, const sf::Vector2f& size,Player& player, Board& board)
	:Monster(position,size,Smart1,TEXTURES_FOR_SMART),m_player(player),m_badDirection(nothing),m_iterations(0),m_board(board)
{}

void SmartMonster::draw(sf::RenderWindow & window)
{
	DinamicObject::draw(window);
	m_spriteIndex %= TEXTURES_FOR_SMART;
}

void SmartMonster::move(const sf::Time& deltaTime)
{
	auto nxtDirection = sf::Vector2f(), destination = sf::Vector2f();
	float currDistance, minDistance = (BOARD_WIDTH*BOARD_WIDTH+BOARD_HEIGHT*BOARD_HEIGHT)* (BOARD_WIDTH * BOARD_WIDTH + BOARD_HEIGHT * BOARD_HEIGHT);
	if (!m_blocked)
	{
		for (int direction = 0; direction < NUM_OF_DIRECTIONS; direction++)
		{
			nxtDirection = Utilities::directionVector(Directions(direction));
			destination = m_sprites[0].getPosition() + nxtDirection * PIXELS_FOR_SEC * deltaTime.asSeconds();
			currDistance = Utilities::distance(destination, m_player.getPosition());
			if (currDistance < minDistance )
			{
				minDistance = currDistance;                     //0527688021
				m_nxtDirection = Directions(direction);
			}
		}
	}
	else
       manageBlocking();
    DinamicObject::move(deltaTime);
}

void SmartMonster::goBack()
{
	DinamicObject::goBack();
	m_blocked = true;
}

void SmartMonster::manageBlocking()
{
	if (m_iterations == 0)
		m_nxtDirection = randomDirection();
	if (m_iterations == 100)
	{
		m_blocked = false;
		m_iterations = 0;
	}
	m_iterations++;
}

Directions SmartMonster::randomDirection() const
{
	if(m_direction == Utilities::directionVector(Up) ||m_direction == Utilities::directionVector(Down))
		return Directions(rand()%2);
	return Directions(rand() % 2 + 2);
}


