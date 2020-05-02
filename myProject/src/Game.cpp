#include "Game.h"

bool Game::run(sf::RenderWindow& window)
{
	bool haveToRestrt = false, sucsses = true;
	int i = 1;
	auto levelFile = std::string ("level1.txt");
		while (std::ifstream(levelFile))
		{
			Level level(m_player, levelFile);
			sucsses = level.run(haveToRestrt, window,i);
			if (!sucsses)
				return false;
			if (!haveToRestrt) {
				m_player.increaseScore(SCORES_FOR_LEVEL);
				i++;
			}
			levelFile = std::string("level")+std::to_string(i) + std::string(".txt");
		}
		return true;
}
