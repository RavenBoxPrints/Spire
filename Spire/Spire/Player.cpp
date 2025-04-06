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
	m_playerSprite.setOrigin(32, SIXFOUR);
	m_playerSprite.setPosition(m_playerSpawn);
}

sf::Sprite Player::getPlayerBody()
{
	return m_playerSprite;
}
