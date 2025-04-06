#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Globals.h"

class Player
{
private:

	void loadPlayerDetail();
	void setupPlayer();

	bool m_alive = true;

	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	sf::Vector2f m_playerSpawn{ SCREEN_WIDTH / 2, 235.0f };

	int m_playerHeading = SOUTH;
	int m_playerSpeed = 3;

public:

	Player();

	void movePlayerUp();
	void movePlayerDown();
	void movePlayerLeft();
	void movePlayerRight();

	sf::Sprite getPlayerBody();
};