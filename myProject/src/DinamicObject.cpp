#include "DinamicObject.h"
#include <iostream>
using namespace std;


//num of textures= how motch textures have a specific diamic object
DinamicObject::DinamicObject(const sf::Vector2f& position, const sf::Vector2f& size, int firstTexture, int numOfTextures)
	:m_spriteIndex(0),m_strtPosition(position),m_direction({1,0}),m_nxtDirection(vectorToDirection()),
	m_strtDirection(m_direction)
{
	for (int texture =  firstTexture; texture < firstTexture+numOfTextures; texture++)
		m_sprites.push_back(create(position, size, texture));
}

void DinamicObject::draw(sf::RenderWindow& window) 
{
	window.draw(m_sprites[0]);
    //window.draw(m_sprites[m_spriteIndex]);
	//m_spriteIndex++;
}

void DinamicObject::move(const sf::Time& deltaTime)
{
	//m_prevPosition = m_sprites[0].getPosition();//save the position that was befor the moving 
	//so we can move the object back in case of colision with a wall etc.
	m_prevPosition = m_sprites[0].getPosition();
	if (m_direction != Utilities::directionVector(m_nxtDirection))
	{
		bool according = matrixMatching();
		if ((rotating() && according) || !rotating())
		{
			transform(m_nxtDirection);
			m_direction = Utilities::directionVector(m_nxtDirection);
			if (according)
				return;
		}
	}
	m_prevPosition = m_sprites[0].getPosition();
	for (auto& sprite : m_sprites)
			sprite.move(m_direction * PIXELS_FOR_SEC * (deltaTime.asSeconds()));
}

sf::Vector2f DinamicObject::getPosition() const
{
		return m_sprites[0].getPosition();	
}

void DinamicObject::replace()
{
	for (auto& sprite : m_sprites)
		sprite.setPosition(m_strtPosition);
	transform(Utilities::vectorToDirection(m_strtDirection));
	m_direction = m_strtDirection;
	m_nxtDirection = vectorToDirection();
}

sf::Vector2i DinamicObject::collisionCell() const
{
	auto width = m_sprites[0].getGlobalBounds().width;
	auto height = m_sprites[0].getGlobalBounds().height;
	auto meetingPoint = collisionPoint();
	return sf::Vector2i(floor(meetingPoint.x / width), floor(meetingPoint.y / height));
}

void DinamicObject::goBack()
{
	for (auto& sprite : m_sprites)
		sprite.setPosition(m_prevPosition);
}

void DinamicObject::checkBoarder()
{
	auto position = getPosition();
	auto width = m_sprites[0].getGlobalBounds().width;
	auto height = m_sprites[0].getGlobalBounds().height;
	if( position.x <= width / 2 || position.y <= height / 2 || position.x >= BOARD_WIDTH - width / 2 || position.y >= BOARD_HEIGHT - height / 2)
		goBack();
	
}

//rotate all sprites in m_sprites
void DinamicObject::setRotation(float angle)
{
	for (auto& sprite : m_sprites)
		sprite.setRotation(angle);
}

void DinamicObject::transform(Directions direction)
{
	float angle = 0; auto factors = sf::Vector2f(1,1);
	switch (direction)
	{
	case Directions::Down:
		angle = 90; 
		factors = (m_direction == Utilities::directionVector(Left)) ?
			sf::Vector2f(-1, 1) : sf::Vector2f(1, 1);  break;
	case Directions::Up:
		angle = 270;
		factors = (m_direction == Utilities::directionVector(Left)) ?
			sf::Vector2f(-1, 1) : sf::Vector2f(1, 1);   break;
	case Directions::Right:
		angle = 0; 
		factors =(m_direction == Utilities::directionVector(Left) )?
			sf::Vector2f(-1,1) : sf::Vector2f(1,1);  break;
	case Directions::Left:
		angle = 0; 
		factors = (m_direction == Utilities::directionVector(Left) )?
		sf::Vector2f(1,1) : sf::Vector2f( -1, 1 ); break;
	}
	for (auto& sprite : m_sprites)
	{
		sprite.setRotation(angle);
		sprite.scale(factors);
	}
}

bool DinamicObject::matrixMatching()
{
	auto side = abs(m_direction.x) * m_sprites[0].getGlobalBounds().width + abs(m_direction.y) * m_sprites[0].getGlobalBounds().height;
	auto prmPos = sf::Vector2f(abs(m_direction.x) * getPosition().x, abs(m_direction.y) * getPosition().y);
	auto later = prmPos + (side / 2) * sf::Vector2f(abs(m_direction.x), abs(m_direction.y));
	auto mana = (later.x + later.y) / side;
	auto standingOn = sf::Vector2f(abs(m_direction.x), abs(m_direction.y)) * floor(mana) * side;
	auto nearTzir = standingOn + m_direction * side;
	auto Distance = Utilities::distance(nearTzir, prmPos) - side / 2;
	if (Distance <= (side)/3)
	{
		for (auto& sprite : m_sprites)
			sprite.move(Distance * m_direction);
		return true;
	}
	return false;
}

bool DinamicObject::rotating() const
{
	auto wanted = sf::Vector2f(Utilities::directionVector(m_nxtDirection));
	return  sf::Vector2f(abs(m_direction.x), abs(m_direction.y))
		!= sf::Vector2f(abs(wanted.x), abs(wanted.y));
}

sf::Vector2f DinamicObject::collisionPoint() const
{
	auto width = m_sprites[0].getGlobalBounds().width;//לשים בפונקציה פרטית!
	auto height = m_sprites[0].getGlobalBounds().height;
	if (m_direction == Utilities::directionVector(Up) ||
		m_direction == Utilities::directionVector(Left))
		return { getPosition().x - width/2 ,getPosition().y - height/2 };
	else if (m_direction == Utilities::directionVector(Down))
		return { getPosition().x - width/2  ,getPosition().y + height /2 };
	return { getPosition().x + width/2 ,getPosition().y - height/2 };
}

Directions DinamicObject::vectorToDirection() const
{
	if (m_direction == Utilities::directionVector(Right))
		return Right;
	if (m_direction == Utilities::directionVector(Down))
		return Down;
	if (m_direction == Utilities::directionVector(Left))
		return Left;
	if (m_direction == Utilities::directionVector(Up))
		return Up;
	return nothing;
}


