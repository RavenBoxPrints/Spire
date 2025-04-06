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

	sf::Texture m_nightImage;
	sf::Sprite m_nightSprite;

	sf::Texture m_cloud1Image;
	sf::Sprite m_cloud1Sprite;

	sf::Texture m_cloud2Image;
	sf::Sprite m_cloud2Sprite;

	sf::Texture m_cloud3Image;
	sf::Sprite m_cloud3Sprite;
	sf::Sprite m_reverseCloud3;
	float m_cloud3Speed = 0.3f;

	sf::Texture m_ray1Image;
	sf::Sprite m_ray1Sprite;

	sf::Texture m_ray2Image;
	sf::Sprite m_ray2Sprite;

	int m_fadeSpeed = 1; // The speed at which the sunrays flicker
	sf::Color m_opacity{ 255,255,255,40 }; // White
	sf::Color m_opacity2{ 255,255,255,20}; // White
	bool fade1 = true;
	bool fade2 = true;

	int m_currentFrame = -1;
	int m_candleFrame = 8; // Total frames in candle animation
	int m_starFrame = 10; // Total frames in star animation
	float m_starFrameCounter = 0.0f;
	float m_candleFrameCounter = 0.0f;
	float m_frameIncrement = 0.15f; // Speed that animation cycles through frames

	sf::Texture m_candleSheet;
	sf::Sprite m_candleSprite;
	const int CANDLEHEIGHT = 64;

	sf::Texture m_starSheet;
	sf::Sprite m_starSprite;

public:

	Citadel();

	void loadCitadelDetail();
	void setupCitadel();

	void animateCitadel(int t_time);
	void animateSunrays();
	void animateClouds();
	void animateNight();

	sf::Sprite getSunrise();
	sf::Sprite getSunset();
	sf::Sprite getNight();
	sf::Sprite getCloud1();
	sf::Sprite getCloud2();
	sf::Sprite getCloud3();
	sf::Sprite getCloud3Add();
	sf::Sprite getCandle();
	sf::Sprite getStars();
	sf::Sprite getCitadel();
	sf::Sprite getRay1();
	sf::Sprite getRay2();

};