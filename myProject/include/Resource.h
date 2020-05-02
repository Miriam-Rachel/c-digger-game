#pragma once
#include <SFML/graphics.hpp>
#include <vector>
#include "macros.h"
#include <SFML/Audio.hpp>
class Resource
{
private:
	//default c-tor  
	Resource();
public:
	static Resource& getInstance();
	//returns a specific texture from the textures vector
	const sf::Texture* operator[](int index) const;

	//returns a specific font from the fonts vector
	//const sf::Font* operator[](int index);
	sf::Font m_font;
	sf::Music m_music;
protected:

	std::vector<sf::Texture> m_textures;

};