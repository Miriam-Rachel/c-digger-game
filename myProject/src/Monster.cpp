#include "Monster.h"
#include "Player.h"

Monster::Monster( const sf::Vector2f& position, const sf::Vector2f& size,int firstTexture, int numOfTextures)
	:DinamicObject(position,size,firstTexture,numOfTextures)
{}
//-----------------שחקן נתקל במפלצת
void Monster::colide(Player& player)
{
	if(player.getGlobalBounds().contains(collisionPoint()) )
	//m_sprites[0].getGlobalBounds().contains(player.collisionPoint())
    // player.getGlobalBounds().intersects(m_sprites[0].getGlobalBounds()))
	{
		player.updateCollision();
		player.reduceLives();
	}
}

