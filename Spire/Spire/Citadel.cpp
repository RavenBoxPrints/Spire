#include "Citadel.h"

Citadel::Citadel()
{
	loadCitadelDetail();
	setupCitadel();
}

void Citadel::loadCitadelDetail()
{
	if (!m_sunriseImage.loadFromFile("ASSETS//IMAGES//sunrise.png"))
	{
		std::cout << "Failed to load sunrise image" << std::endl;
	}
	if (!m_sunsetImage.loadFromFile("ASSETS//IMAGES//sunset.png"))
	{
		std::cout << "Failed to load sunset image" << std::endl;
	}
	if (!m_nightImage.loadFromFile("ASSETS//IMAGES//night.png"))
	{
		std::cout << "Failed to load night image" << std::endl;
	}
	if (!m_cloud1Image.loadFromFile("ASSETS//IMAGES//cloud1.png"))
	{
		std::cout << "Failed to load cloud1 image" << std::endl;
	}
	if (!m_cloud2Image.loadFromFile("ASSETS//IMAGES//cloud2.png"))
	{
		std::cout << "Failed to load cloud2 image" << std::endl;
	}
	if (!m_cloud3Image.loadFromFile("ASSETS//IMAGES//cloud3.png"))
	{
		std::cout << "Failed to load cloud3 image" << std::endl;
	}
	if (!m_starSheet.loadFromFile("ASSETS//IMAGES//stars.png"))
	{
		std::cout << "Failed to load star sheet" << std::endl;
	}
	if (!m_candleSheet.loadFromFile("ASSETS//IMAGES//candles.png"))
	{
		std::cout << "Failed to load candle sheet" << std::endl;
	}
	if (!m_citImage.loadFromFile("ASSETS//IMAGES//citadel.png"))
	{
		std::cout << "Failed to load citadel image" << std::endl;
	}
	if (!m_ray1Image.loadFromFile("ASSETS//IMAGES//rays1.png"))
	{
		std::cout << "Failed to load sunrays1 image" << std::endl;
	}
	if (!m_ray2Image.loadFromFile("ASSETS//IMAGES//rays2.png"))
	{
		std::cout << "Failed to load sunrays2 image" << std::endl;
	}
}

void Citadel::setupCitadel()
{
	m_sunriseSprite.setTexture(m_sunriseImage);
	m_sunsetSprite.setTexture(m_sunsetImage);
	m_nightSprite.setTexture(m_nightImage);

	m_cloud1Sprite.setTexture(m_cloud1Image);
	m_cloud2Sprite.setTexture(m_cloud2Image);
	m_cloud3Sprite.setTexture(m_cloud3Image);
	m_reverseCloud3.setTexture(m_cloud3Image);
	m_reverseCloud3.setPosition(SCREEN_WIDTH, 0);

	m_starSprite.setTexture(m_starSheet);
	m_starSprite.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	m_candleSprite.setTexture(m_candleSheet);
	m_candleSprite.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, 64));
	m_citSprite.setTexture(m_citImage);

	m_ray1Sprite.setTexture(m_ray1Image);
	m_ray2Sprite.setTexture(m_ray2Image);
	m_ray1Sprite.setColor(m_opacity);
	m_ray2Sprite.setColor(m_opacity2);
}

void Citadel::animateCitadel(int t_time)
{
	if (t_time == SUNRISE || t_time == SUNSET)
	{
		animateSunrays();
		animateClouds();
	}
}

void Citadel::animateSunrays()
{
	if (fade1 == true)
	{
		m_opacity.a -= m_fadeSpeed;

		if (m_opacity.a <= 0)
		{
			fade1 = false;
		}
	}

	else if (fade1 == false)
	{
		m_opacity.a += m_fadeSpeed;

		if (m_opacity.a >= 40)
		{
			fade1 = true;
		}
	}
	if (fade2 == true)
	{
		m_opacity2.a -= m_fadeSpeed;

		if (m_opacity2.a <= 0)
		{
			fade2 = false;
		}
	}

	else if (fade2 == false)
	{
		m_opacity2.a += m_fadeSpeed;

		if (m_opacity2.a >= 40)
		{
			fade2 = true;
		}
	}

	m_ray1Sprite.setColor(m_opacity);
	m_ray2Sprite.setColor(m_opacity2);
}

void Citadel::animateClouds()
{
	float posx = m_cloud3Sprite.getPosition().x;
	float pos1x = m_reverseCloud3.getPosition().x;

	posx -= m_cloud3Speed;
	pos1x -= m_cloud3Speed;

	m_cloud3Sprite.setPosition(posx, 0.0f);
	m_reverseCloud3.setPosition(pos1x, 0.0f);

	if (m_cloud3Sprite.getPosition().x <= -SCREEN_WIDTH)
	{
		m_cloud3Sprite.setPosition(SCREEN_WIDTH, ZERO);
	}

	if (m_reverseCloud3.getPosition().x <= -SCREEN_WIDTH)
	{
		m_reverseCloud3.setPosition(SCREEN_WIDTH, ZERO);
	}
}

sf::Sprite Citadel::getSunrise()
{
	return m_sunriseSprite;
}

sf::Sprite Citadel::getSunset()
{
	return m_sunsetSprite;
}

sf::Sprite Citadel::getNight()
{
	return m_nightSprite;
}

sf::Sprite Citadel::getCloud1()
{
	return m_cloud1Sprite;
}

sf::Sprite Citadel::getCloud2()
{
	return m_cloud2Sprite;
}

sf::Sprite Citadel::getCloud3()
{
	return m_cloud3Sprite;
}

sf::Sprite Citadel::getCloud3Add()
{
	return m_reverseCloud3;
}

sf::Sprite Citadel::getCandle()
{
	return m_candleSprite;
}

sf::Sprite Citadel::getStars()
{
	return m_starSprite;
}

sf::Sprite Citadel::getCitadel()
{
	return m_citSprite;
}

sf::Sprite Citadel::getRay1()
{
	return m_ray1Sprite;
}

sf::Sprite Citadel::getRay2()
{
	return m_ray2Sprite;
}
