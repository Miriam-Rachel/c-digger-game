#include "Info.h"
#include <iostream>

Info::Info()
{
	/*m_printLives = sf::Text("LIVES:", Resource::getInstance().m_font);
	m_printLives.setPosition(1000, 150);
	m_printLives.setColor(sf::Color::Black);
	m_lives.setPosition(1020,150);
	m_lives.setColor(sf::Color::Black);
	m_printScore = sf::Text("SCORE:", Resource::getInstance().m_font);
	m_printScore.setPosition(1000, 270);
	m_printScore.setColor(sf::Color::Black);
	m_score.setPosition(1120,270);
	m_score.setColor(sf::Color::Black);
	m_printStones = sf::Text("STONES:", Resource::getInstance().m_font);
	m_printStones.setPosition(1100, 390);
	m_printStones.setColor(sf::Color::Black);
	m_stones.setPosition(1120,390);
	m_stones.setColor(sf::Color::Black);
	m_printLevel = sf::Text("LEVEL:", Resource::getInstance().m_font);
	m_printLevel.setPosition(1100, 510);
	m_printLevel.setColor(sf::Color::Black);
	m_level.setPosition(1120,510);
	m_level.setColor(sf::Color::Black);
	m_level.setFont(Resource::getInstance().m_font);
	m_stones.setFont(Resource::getInstance().m_font);
	m_score.setFont(Resource::getInstance().m_font);
	m_lives.setFont(Resource::getInstance().m_font);*/


	auto blue = sf::Color(0, 191, 255);
	m_printLives = sf::Text("LIVES:", Resource::getInstance().m_font);
	m_printLives.setPosition(1000, 200);
	m_printLives.setColor(blue);
	/*m_lives.setPosition(1110, 150);
	m_lives.setColor(sf::Color::White);
	m_lives.setFont(Resource::getInstance().m_font);*/
	m_printScore = sf::Text("SCORE:", Resource::getInstance().m_font);
	m_printScore.setPosition(1000, 320);
	m_printScore.setColor(blue);
	/*m_score.setPosition(1100, 270);
	m_score.setColor(sf::Color::White);
	m_score.setFont(Resource::getInstance().m_font);*/
	m_printStones = sf::Text("STONES:", Resource::getInstance().m_font);
	m_printStones.setPosition(1000, 440);
	m_printStones.setColor(blue);
	/*m_stones.setPosition(1100, 390);
	m_stones.setColor(sf::Color::White);
	m_stones.setFont(Resource::getInstance().m_font);*/
	m_printLevel = sf::Text("LEVEL:", Resource::getInstance().m_font);
	m_printLevel.setPosition(1000, 560);
	m_printLevel.setColor(blue);
	/*m_level.setPosition(1100, 510);
	m_level.setColor(sf::Color::White);
	m_level.setFont(Resource::getInstance().m_font);*/
}

//-------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
void Info::displayInformation(const int lives, const int stone, const int score, const int level, const int time, sf::RenderWindow& window)
{

	//m_lives.setString(std::to_string(lives));
	//m_stones.setString(std::to_string(stone));
	//m_score.setString(std::to_string(score));
	//m_level.setString(std::to_string(level));
	//window.draw(m_printLives);
	//window.draw(m_lives);
	//window.draw(m_printScore);
	//window.draw(m_score);
	//window.draw(m_printLevel);
	//window.draw(m_level);
	//window.draw(m_printStones);
	//window.draw(m_stones);
	////displayTime(time, window)
	auto text = sf::Text(std::to_string(time), Resource::getInstance().m_font);
	text.setPosition(1020, 50);
	text.setCharacterSize(54);
	text.setFillColor(sf::Color::Red);
	window.draw(text);

	window.draw(m_printLives);
	text = sf::Text(std::to_string(lives), Resource::getInstance().m_font);
	text.setPosition(m_printLives.getGlobalBounds().width / 2 + m_printLives.getPosition().x, 250);
	text.setFillColor(sf::Color::White);
	window.draw(text);

	window.draw(m_printStones);
	text = sf::Text(std::to_string(score), Resource::getInstance().m_font);
	text.setPosition(m_printStones.getGlobalBounds().width / 2 + m_printStones.getPosition().x, 370);
	text.setFillColor(sf::Color::White);
	window.draw(text);

	window.draw(m_printScore);
	text = sf::Text(std::to_string(stone), Resource::getInstance().m_font);
	text.setPosition(m_printScore.getGlobalBounds().width / 2 + m_printScore.getPosition().x, 490);
	text.setFillColor(sf::Color::White);
	window.draw(text);

	window.draw(m_printLevel);
	text = sf::Text(std::to_string(level), Resource::getInstance().m_font);
	text.setPosition(m_printLevel.getGlobalBounds().width / 2 + m_printLevel.getPosition().x, 610);
	text.setFillColor(sf::Color::White);
	window.draw(text);
}

Info& Info::getInstance()
{
	static  Info m_instance;
	return m_instance;
}


















//void DisplayData::displayData(const int lives, const int score, const int stones, const int level, const float time, sf::RenderWindow& window)
//{
//	window.draw(m_printLives);   
//	auto text = sf::Text(std::to_string(lives), Resources::getInstance().m_font);
//	text.setPosition(m_printLives.getPosition().x + m_printLives.getGlobalBounds().width, 0);
//	text.setColor(sf::Color::Black);
//	window.draw(text);
//	window.draw(m_printScore);
//	auto  text2 = sf::Text(std::to_string(score), Resources::getInstance().m_font);
//	text2.setPosition(m_printScore.getPosition().x + m_printScore.getGlobalBounds().width, 0);
//	text2.setColor(sf::Color::Black);
//	window.draw(text2);
//	window.draw(m_printStones);
//	auto  text3 = sf::Text(std::to_string(stones), Resources::getInstance().m_font);
//	text3.setPosition(m_printStones.getPosition().x + m_printStones.getGlobalBounds().width, 0);
//	text3.setColor(sf::Color::Black);
//	window.draw(text3);
//	window.draw(m_printLevel);
//	auto  text4 = sf::Text(std::to_string(level), Resources::getInstance().m_font);
//	text4.setPosition(m_printLevel.getPosition().x + m_printLevel.getGlobalBounds().width, 0);
//	text4.setColor(sf::Color::Black);
//	window.draw(text4);
//}


