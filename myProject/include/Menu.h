#pragma once
#include <vector>
#include "Resource.h"
#include "Button.h"
#include "macros.h"
#include "NewGame.h"
#include "ExitGame.h"
class Menu
{
public:
	Menu(const Menu&) = delete;

	Menu& operator=(const Menu&) = delete;

	Menu(sf::RenderWindow& window);
	bool run();//אולי להעביר לפרייבט
	void drawOnWindow();
	bool handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window);
	~Menu();
protected:
	sf::RenderWindow& m_window;
	sf::Sprite m_background;
	sf::Sprite m_visualPlayer;
	std::vector <Button*> m_menu;

};