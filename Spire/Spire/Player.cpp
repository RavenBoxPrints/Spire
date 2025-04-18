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
	m_playerSprite.setTextureRect(sf::IntRect{ 0, 0, 64, 64});
	m_playerSprite.setOrigin(32, 58);
	m_playerSprite.setPosition(m_playerSpawn);
}

void Player::animatePlayer()
{
	m_frameCounter += m_frameIncrement;
	column = static_cast<int>(m_frameCounter);

	if (m_playerHeading == NORTH)
	{
		m_playerSprite.setScale(1.0f, 1.0f);

		if (m_playerAction == STAND)
		{
			m_totalFrames = 6;
			m_frameIncrement = 0.15f;
			row = 1;
		}

		else if (m_playerAction == WALK)
		{
			m_totalFrames = 4;
			m_frameIncrement = 0.15f;
			row = 4;
		}
	}

	else if (m_playerHeading == SOUTH)
	{
		m_playerSprite.setScale(1.0f, 1.0f);

		if (m_playerAction == STAND)
		{
			m_totalFrames = 6;
			m_frameIncrement = 0.15f;
			row = 0;
		}

		else if (m_playerAction == WALK)
		{
			m_totalFrames = 4;
			m_frameIncrement = 0.15f;
			row = 3;
		}
	}

	else if (m_playerHeading == EAST)
	{
		m_playerSprite.setScale(1.0f, 1.0f);

		if (m_playerAction == STAND)
		{
			m_totalFrames = 6;
			m_frameIncrement = 0.15f;
			row = 2;
		}

		if (m_playerAction == WALK)
		{
			m_totalFrames = 4;
			m_frameIncrement = 0.2f;
			row = 5;
		}
	}

	else if (m_playerHeading == WEST)
	{
		m_playerSprite.setScale(-1.0f, 1.0f);

		if (m_playerAction == STAND)
		{
			m_totalFrames = 6;
			m_frameIncrement = 0.15f;
			row = 2;
		}

		if (m_playerAction == WALK)
		{
			m_totalFrames = 4;
			m_frameIncrement = 0.2f;
			row = 5;
		}
	}

	if (column >= m_totalFrames)
	{
		column = 0;
		m_frameCounter = 0.0f;
	}

	m_playerSprite.setTextureRect(sf::IntRect{ column * 64, row * 64, 64, 64 });
}

void Player::setHeading(int t_heading)
{
	m_playerHeading = t_heading;
}

void Player::setAction(int t_action)
{
	m_playerAction = t_action;
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
	{
		movePlayerUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
	{
		movePlayerDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
	{
		movePlayerLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
	{
		movePlayerRight();
	}
}

void Player::movePlayerUp()
{
	sf::Vector2f pos = m_playerSprite.getPosition();

	m_playerHeading = NORTH;

	if (pos.y > 155)
	{
		m_playerAction = WALK;
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
		m_playerAction = WALK;
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
		m_playerAction = WALK;
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
		m_playerAction = WALK;
		pos.x += m_playerSpeed;
		m_playerSprite.setPosition(pos);
	}
}

sf::Vector2f Player::getLocation()
{
	return m_playerSprite.getPosition();
}

sf::Sprite Player::getPlayerBody()
{
	return m_playerSprite;
}

bool Player::isAlive()
{
	return m_alive;
}
