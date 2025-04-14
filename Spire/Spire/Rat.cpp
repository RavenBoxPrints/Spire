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
	m_ratSprite.setOrigin(58, 32);
}

void Rat::spawn()
{
	m_heading = (rand() % 2) + 3;

	if (m_heading == EAST)
	{
		m_ratSprite.setScale(1.0f, 1.0f);
		// m_ratSprite.setPosition(0.0f, (rand() % 1) + SCREEN_HEIGHT);
		m_ratSprite.setPosition(100.0f, (SCREEN_HEIGHT - 50));
	}

	if (m_heading == WEST)
	{
		m_ratSprite.setScale(-1.0f, 1.0f);
		// m_ratSprite.setPosition(SCREEN_WIDTH, (rand() % 1) + SCREEN_HEIGHT);
		m_ratSprite.setPosition(SCREEN_WIDTH - 100.0f, (SCREEN_HEIGHT - 50));
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
			m_totalFrames = 5;
			m_frameIncrement = 0.15;
		}

		if (m_heading == WEST)
		{
			m_ratSprite.setScale(-1.0f, 1.0f);
			m_totalFrames = 5;
			m_frameIncrement = 0.15;
		}
	}

	if (column >= m_totalFrames)
	{
		m_frameCounter = 0.0f;
	}

	m_ratSprite.setTextureRect({ column * 80, row * 32, 80, 32 });
}

sf::Sprite Rat::getBody()
{
	return m_ratSprite;
}

bool Rat::getAlive()
{
	return m_alive;
}
