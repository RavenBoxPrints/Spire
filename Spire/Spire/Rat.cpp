#include "Rat.h"

Rat::Rat()
{
	loadTexture();
	setup();
	spawn();
}

void Rat::loadTexture()
{
	if (!m_ratTexture.loadFromFile("ASSETS//IMAGES//rat.png"))
	{
		std::cout << "Issue loading rat texture" << std::endl;
	}
}

void Rat::setup()
{
	m_ratSprite.setTexture(m_ratTexture);
	m_ratSprite.setTextureRect(sf::IntRect(0, 0, 80, 32));
	m_ratSprite.setOrigin(65, 32);

	m_detect.setRadius(100.0f);
	m_detect.setOrigin(100.0f, 100.0f);
	m_detect.setScale(1.0f, 0.5f);
	m_detect.setFillColor(sf::Color::Transparent);
	m_detect.setOutlineColor(sf::Color::Red);
	m_detect.setOutlineThickness(2);
}

void Rat::spawn()
{
	m_heading = (rand() % 2) + 3;

	if (m_heading == EAST)
	{
		m_ratSprite.setScale(1.0f, 1.0f);
		m_ratSprite.setPosition((rand() % 26),(rand () % 116) + 155); // (0 - 25, 155 - 270)
	}

	if (m_heading == WEST)
	{
		m_ratSprite.setScale(-1.0f, 1.0f);
		m_ratSprite.setPosition((rand() % 26) + 455, (rand() % 116) + 155); // (455 - 480, 155 - 270)
	}
}

void Rat::animate()
{
	m_frameCounter += m_frameIncrement;
	column = static_cast<int>(m_frameCounter);

	if (m_action == WALK)
	{
		if (m_heading == EAST)
		{
			m_ratSprite.setScale(1.0f, 1.0f);
		}

		if (m_heading == WEST)
		{
			m_ratSprite.setScale(-1.0f, 1.0f);
		}
	}

	if (column >= m_totalFrames)
	{
		m_frameCounter = 0.0f;
	}

	m_ratSprite.setTextureRect({ column * 80, 0, 80, 32 });
}

void Rat::move(sf::Vector2f t_playerPos)
{
	sf::Vector2f m_ratPos = m_ratSprite.getPosition();

	if (m_ratPos.x < t_playerPos.x - SPACE)
	{
		m_heading = EAST;
		m_ratPos.x += m_speed;
	}

	if (m_ratPos.x > t_playerPos.x + SPACE)
	{
		m_heading = WEST;
		m_ratPos.x -= m_speed;
	}

	if (m_ratPos.y < t_playerPos.y)
	{
		m_ratPos.y += m_speed;
		m_layer = BEHIND;
	}

	if (m_ratPos.y > t_playerPos.y)
	{
		m_ratPos.y -= m_speed;
		m_layer = FRONT;
	}

	m_ratSprite.setPosition(m_ratPos);
	m_detect.setPosition(m_ratPos.x,m_ratPos.y - 22);
}

sf::Sprite Rat::getBody()
{
	return m_ratSprite;
}

sf::CircleShape Rat::getDetect()
{
	return m_detect;
}

bool Rat::getAlive()
{
	return m_alive;
}

int Rat::getLayer()
{
	return m_layer;
}
