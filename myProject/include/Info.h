#pragma once
#include <SFML/Graphics.hpp>
#include "macros.h"
#include "Resource.h"

//צריך להדפיס את: מספר הנקודות שצבר,מספר חיים שנותר,מספר האבנים שמותר לאכול,זמן שנותר לו והשלב הנוכחי
class Info
{
public:

	void displayInformation(const int lives, const int stone, const int score, const int level, const int time, sf::RenderWindow& window);
	static Info& getInstance();
protected:

	sf::Text m_printLives;
	sf::Text m_printStones;
	sf::Text m_printScore;
	sf::Text m_printLevel;
	sf::Text m_lives;
	sf::Text m_stones;
	sf::Text m_score;
	sf::Text m_level;

private:
	Info();
	Info(const Info&) = default;
	Info& operator=(const Info&) = default;


};