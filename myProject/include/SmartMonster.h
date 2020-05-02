#pragma once
#include "Monster.h"
#include "Player.h"


class Board;

class SmartMonster : public Monster
{
public:
	SmartMonster( const sf::Vector2f& position, const sf::Vector2f& size, Player& player, Board& board);
	virtual void draw(sf::RenderWindow& window)override;
	virtual void move(const sf::Time& deltaTime)override;
	virtual void goBack()override;
	virtual ~SmartMonster() = default;
protected:
	Player& m_player;
	Directions m_badDirection;
	bool m_blocked = false;
	int m_iterations;
	void manageBlocking();
	Directions randomDirection() const;
	Board& m_board;
};