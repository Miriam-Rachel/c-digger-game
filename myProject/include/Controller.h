#pragma once
#include "Game.h"
#include "Menu.h"

class Controller
{
public:
	Controller();
	void run();
	void run2();
protected:
	sf::RenderWindow m_window;
	Menu m_menu;//���� �� �������
	

	void gameOver();
	void won();
};