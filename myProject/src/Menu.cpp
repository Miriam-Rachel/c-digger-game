#include "Menu.h"

Menu::Menu(sf::RenderWindow& window) :m_window(window), m_background(*(Resource::getInstance()[BackgroundMenu])), m_visualPlayer(*(Resource::getInstance()[Diver2]))
//Menu::Menu() :m_window(sf::VideoMode(WIDTH_OF_WINDOW, HEIGHT_OF_WINDOW), "menu"), m_background(*(Resource::instance()[BackgroundMenu]))
{
	//m_background.setPosition({ 0,0 });
	//m_background.setScale(1280, 720);
	//
	m_visualPlayer.setPosition(400, 195);
	for (int button = 0; button < NUM_OF_BUTTONS; button++)
	{
		m_menu.push_back(new (std::nothrow) NewGame(NewGame1));
		m_menu.push_back(new (std::nothrow) ExitGame(Exit1));
	}

}

bool Menu::run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		drawOnWindow();
		m_window.display();
		for (auto event = sf::Event{}; m_window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
				if (handleClick(event.mouseButton, m_window)) {
					//m_window.clear();
					return true;
					break;
				}
			}
		}
	}
	return false;
}
//-----------------------------------------------------
void Menu::drawOnWindow()
{
	m_window.draw(m_background);
	m_window.draw(m_visualPlayer);
	for (auto button : m_menu)
		button->drawOnWindow(m_window);

}
//------------------------------------------------
bool Menu::handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	for (Button* button : m_menu)
		//for (int i = 0; i < 2; i++)
		if (button->handleClick(event, m_window))
			//if (m_menu[i]->handleClick(event, m_window))
			return true;
	return false;
}

Menu::~Menu()
{
	for (auto button : m_menu)
		delete button;
}
