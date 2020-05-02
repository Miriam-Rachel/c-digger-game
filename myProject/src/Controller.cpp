#include "Controller.h"

Controller::Controller() :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "game"),m_menu(m_window)
{}



void Controller::run()
{
	srand(time(0));
	bool sucsses = true;
		while (m_menu.run())
		{
			Game game;
			sucsses = game.run(m_window);
			sucsses ? won() : gameOver();
		}
	}


void Controller::gameOver()
{

	int index = 0;
	auto sprite = sf::Sprite(*(Resource::getInstance()[gameover]));
	while (index < 1000)
	{
		m_window.clear();
		m_window.draw(sprite);
		m_window.display();
		index++;
	}

}


void Controller::won()
{

	int index = 0;
	auto sprite = sf::Sprite(*(Resource::getInstance()[win]));
	

	while (index < 2000)
	{
		m_window.clear();
		m_window.draw(sprite);
		m_window.display();
		index++;
	}
}


