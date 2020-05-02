#pragma once
#include<SFML/Graphics.hpp>
#include "Resource.h"

class Button
{
public:
	Button(int name, const sf::Vector2f& position);
	void drawOnWindow(sf::RenderWindow& window);
	virtual bool handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window) = 0;
	bool isContain(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window);
	virtual ~Button() = default;
protected:
	sf::Sprite m_sprite;

};

