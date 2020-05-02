#pragma once
#include "macros.h"
#include <SFML\Graphics.hpp>
class Utilities
{
public:
	static sf::Vector2f directionVector(Directions direction);
	static Directions keyToDirection(sf::Keyboard::Key key);
	static float distance(const sf::Vector2f& point1, const sf::Vector2f& point2);
	static bool isInt(float c);
	static Directions vectorToDirection(const sf::Vector2f& direction);
  };