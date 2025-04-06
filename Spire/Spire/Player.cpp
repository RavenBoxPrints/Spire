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

void Player::movePlayerUp()
{
	int posx = m_playerSprite.getPosition().x;
	int posy = m_playerSprite.getPosition().y;

	m_playerHeading = NORTH;

	if (posy > 155)
	{
		posy -= m_playerSpeed;
		m_playerSprite.setPosition(posx, posy);
	}
}

void Player::movePlayerDown()
{
	int posx = m_playerSprite.getPosition().x;
	int posy = m_playerSprite.getPosition().y;

	m_playerHeading = SOUTH;

	if (posy < SCREEN_HEIGHT)
	{
		posy += m_playerSpeed;
		m_playerSprite.setPosition(posx, posy);
	}
}

void Player::movePlayerLeft()
{
	int posx = m_playerSprite.getPosition().x;
	int posy = m_playerSprite.getPosition().y;

	m_playerHeading = WEST;

	if (posx > 16)
	{
		posx -= m_playerSpeed;
		m_playerSprite.setPosition(posx, posy);
	}
}

void Player::movePlayerRight()
{
	int posx = m_playerSprite.getPosition().x;
	int posy = m_playerSprite.getPosition().y;

	m_playerHeading = WEST;

	if (posx < SCREEN_WIDTH - 16)
	{
		posx += m_playerSpeed;
		m_playerSprite.setPosition(posx, posy);
	}
}

sf::Sprite Player::getPlayerBody()
{
	return m_playerSprite;
}
