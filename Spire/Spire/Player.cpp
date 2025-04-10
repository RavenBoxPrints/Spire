#include "Player.h"

Player::Player()
{
	loadPlayerDetail();
	setupPlayer();
}

void Player::loadPlayerDetail()
{
	if (!m_playerTexture.loadFromFile("ASSETS//IMAGES//player.png"))
	{
		std::cout << "Issue loading player sprite sheet" << std::endl;
	}
}

void Player::setupPlayer()
{
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setTextureRect(sf::IntRect{ 0, 0, SIXFOUR, SIXFOUR});
	m_playerSprite.setOrigin(32, SIXFOUR - 4);
	m_playerSprite.setPosition(m_playerSpawn);
}

void Player::animatePlayer()
{
	m_frameCounter += m_frameIncrement;
	column = static_cast<int>(m_frameCounter);

	if (m_playerHeading == NONE)
	{
		m_totalFrames = 5;
		m_frameIncrement = 0.15;
		row = 0;
	}

	else if (m_playerHeading == NORTH)
	{
		m_totalFrames = 4;
		m_frameIncrement = 0.15;
		row = 1;
	}

	else if (m_playerHeading == SOUTH)
	{
		m_totalFrames = 4;
		m_frameIncrement = 0.15;
		row = 2;
	}

	else if (m_playerHeading == EAST)
	{
		m_totalFrames = 4;
		m_frameIncrement = 0.15;
		row = 4;
	}

	else if (m_playerHeading == WEST)
	{
		m_totalFrames = 4;
		m_frameIncrement = 0.15;
		row = 3;
	}

	if (column >= m_totalFrames)
	{
		column = 0;
		m_frameCounter = 0.0f;
	}

	m_playerSprite.setTextureRect(sf::IntRect{ column * SIXFOUR, row * SIXFOUR, SIXFOUR, SIXFOUR });
}

void Player::setHeading(int t_heading)
{
	m_playerHeading = t_heading;
}

void Player::movePlayerUp()
{
	sf::Vector2f pos = m_playerSprite.getPosition();


	if (pos.y > 155)
	{
		m_playerHeading = NORTH;
		pos.y -= m_playerSpeed;
		m_playerSprite.setPosition(pos);
	}
}

void Player::movePlayerDown()
{
	sf::Vector2f pos = m_playerSprite.getPosition();

	m_playerHeading = SOUTH;

	if (pos.y < SCREEN_HEIGHT)
	{
		pos.y += m_playerSpeed;
		m_playerSprite.setPosition(pos);
	}
}

void Player::movePlayerLeft()
{
	sf::Vector2f pos = m_playerSprite.getPosition();

	m_playerHeading = WEST;

	if (pos.x > 16)
	{
		pos.x -= m_playerSpeed;
		m_playerSprite.setPosition(pos);
	}
}

void Player::movePlayerRight()
{
	sf::Vector2f pos = m_playerSprite.getPosition();

	m_playerHeading = EAST;

	if (pos.x < SCREEN_WIDTH - 16)
	{
		pos.x += m_playerSpeed;
		m_playerSprite.setPosition(pos);
	}
}

sf::Sprite Player::getPlayerBody()
{
	return m_playerSprite;
}

bool Player::isAlive()
{
	return m_alive;
}
