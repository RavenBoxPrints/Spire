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
	m_cloud1Sprite.setTexture(m_cloud1Image);
	m_cloud2Sprite.setTexture(m_cloud2Image);
	m_cloud3Sprite.setTexture(m_cloud3Image);
	m_candleSprite.setTexture(m_candleSheet);
	m_citSprite.setTexture(m_citImage);

	m_ray1Sprite.setTexture(m_ray1Image);
	m_ray1Sprite.setColor(sf::Color(255.0f, 255.0f, 255.0f, m_ray1Opacity));

	m_ray2Sprite.setTexture(m_ray2Image);
	m_ray2Sprite.setColor(sf::Color(255.0f, 255.0f, 255.0f, m_ray2Opacity));
}

void Citadel::animateCitadel()
{
	animateSunrays();
}

void Citadel::animateSunrays()
{
	if (ray1Fading == true)
	{
		m_ray1Opacity -= m_fadeSpeed;
		m_ray1Sprite.setColor(sf::Color(255.0f, 255.0f, 255.0f, m_ray1Opacity));

		if (m_ray1Opacity == 0.0f);
		{
			ray1Fading = false;
		}
	}

	if (ray1Fading == false)
	{
		m_ray1Opacity += m_fadeSpeed;
		m_ray1Sprite.setColor(sf::Color(255.0f, 255.0f, 255.0f, m_ray1Opacity));

		if (m_ray1Opacity == 100.0f)
		{
			ray1Fading = true;
		}
	}

	if (ray2Fading == true)
	{
		m_ray2Opacity -= m_fadeSpeed;
		m_ray2Sprite.setColor(sf::Color(255.0f, 255.0f, 255.0f, m_ray2Opacity));

		if (m_ray2Opacity == 0.0f);
		{
			ray2Fading = false;
		}
	}

	if (ray2Fading == false)
	{
		m_ray2Opacity += m_fadeSpeed;
		m_ray2Sprite.setColor(sf::Color(255.0f, 255.0f, 255.0f, m_ray2Opacity));

		if (m_ray2Opacity == 100.0f)
		{
			ray2Fading = true;
		}
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

sf::Sprite Citadel::getCandle()
{
	return m_candleSprite;
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
