#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Globals.h"

class Citadel
{
private:

	sf::Texture m_citImage;
	sf::Sprite m_citSprite;

	sf::Texture m_sunriseImage;
	sf::Sprite m_sunriseSprite;

	sf::Texture m_sunsetImage;
	sf::Sprite m_sunsetSprite;

	sf::Texture m_cloud1Image;
	sf::Sprite m_cloud1Sprite;

	sf::Texture m_cloud2Image;
	sf::Sprite m_cloud2Sprite;

	sf::Texture m_cloud3Image;
	sf::Sprite m_cloud3Sprite;
	
	sf::Texture m_ray1Image;
	sf::Sprite m_ray1Sprite;

	sf::Texture m_ray2Image;
	sf::Sprite m_ray2Sprite;

	sf::Texture m_candleSheet;
	sf::Sprite m_candleSprite;

public:

	Citadel();

	void loadCitadelDetail();
	void setupCitadel();

	sf::Sprite getSunrise();
	sf::Sprite getSunset();
	sf::Sprite getCloud1();
	sf::Sprite getCloud2();
	sf::Sprite getCloud3();
	sf::Sprite getCandle();
	sf::Sprite getCitadel();
	sf::Sprite getRay1();
	sf::Sprite getRay2();

};