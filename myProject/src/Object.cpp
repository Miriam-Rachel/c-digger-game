#include "Object.h"
#include "Player.h"

sf::Sprite Object::create(const sf::Vector2f& position, const sf::Vector2f& size,int index)
{
	auto texture = (Resource::getInstance())[index];
	auto sprite = sf::Sprite(*texture);
	sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize() / 2u));
	sprite.setPosition(position);
	auto texSize = texture->getSize();
	auto newTexSize = sf::Vector2u(size);
	auto scaleX = newTexSize.x * 1.00f / texSize.x;
	auto scaleY = newTexSize.y * 1.00f / texSize.y;
	sprite.scale(scaleX, scaleY);
	return sprite;
}

sf::Sprite Object::scale(const sf::Vector2f& size,sf::Sprite sprite) const
{
	auto texture = sprite.getTexture();
	auto texSize = texture->getSize();
	auto newTexSize = sf::Vector2u(size);
	auto scaleX = newTexSize.x * 1.00f / texSize.x;
	auto scaleY = newTexSize.y * 1.00f / texSize.y;
	sprite.scale(scaleX, scaleY);
	return sprite;
}


