#pragma once
#include "Level.h"
#include "Player.h"

class Game
{
public:
	Game() = default;
    bool run(sf::RenderWindow& window);
protected:
	Player m_player;
};