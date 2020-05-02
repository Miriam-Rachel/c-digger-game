#include "Resource.h"

Resource::Resource()
{

	for (int texture = 0; texture < NUM_OF_TEXTURES; texture++)
		m_textures.push_back(sf::Texture());
	
		m_textures[0].loadFromFile("background.jpg");
		m_textures[1].loadFromFile("backgroundMenu2.jpg");
		m_textures[2].loadFromFile("diver1.png");
		m_textures[3].loadFromFile("diver2.png");
		m_textures[4].loadFromFile("diver3.png");
		m_textures[5].loadFromFile("diver4.png");
		m_textures[6].loadFromFile("exit1.png");
		m_textures[7].loadFromFile("newGame1.png");
		m_textures[8].loadFromFile("pearl.png");
		m_textures[9].loadFromFile("present.png");
		m_textures[10].loadFromFile("shark1.png");
		m_textures[11].loadFromFile("shark2.png");
		m_textures[12].loadFromFile("shark3.png");
		m_textures[13].loadFromFile("smart1.png");
		m_textures[14].loadFromFile("smart2.png");
		m_textures[15].loadFromFile("smart3.png");
		m_textures[16].loadFromFile("smart4.png");
		m_textures[17].loadFromFile("smart5.png");
		m_textures[18].loadFromFile("stone.png");
		m_textures[19].loadFromFile("wall.png");
		m_textures[20].loadFromFile("gameOver.png");
		m_textures[21].loadFromFile("win.jpg");

		m_font.loadFromFile("c:/Windows/Fonts/PRISTINA.ttf");
		m_music.openFromFile("music.wav");
}

Resource& Resource::getInstance()
{
	static Resource m_instance;
	return m_instance;
}

const sf::Texture* Resource::operator[](int index)const
{
	return &m_textures[index];
}
