#include "Utilities.h"


sf::Vector2f Utilities::directionVector(Directions direction)
{
	switch (direction)
	{
	case Directions::Up:
		return { 0, -1 };
		break;
	case Directions::Down:
		return { 0,1 };
		break;
	case Directions::Right:
		return { 1,0 };
		break;
	case Directions::Left:
		return  { -1,0 };
		break;
	default :
		return { 0,0 }; break;
	}
}

Directions Utilities::keyToDirection(sf::Keyboard::Key key)
{
	return Directions(key - SUBPRACT);
}

float Utilities::distance(const sf::Vector2f& point1, const sf::Vector2f& point2)
{
	return abs(point1.x - point2.x) + abs(point1.y - point2.y);
}

bool Utilities::isInt(float c)
{
	return floor(c) == c;
}

Directions Utilities::vectorToDirection(const sf::Vector2f& direction)
{
	if (direction == Utilities::directionVector(Right))
		return Right;
	if (direction == Utilities::directionVector(Down))
		return Down;
	if (direction == Utilities::directionVector(Left))
		return Left;
	if (direction == Utilities::directionVector(Up))
		return Up;
	return nothing;
}


