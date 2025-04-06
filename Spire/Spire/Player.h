#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Globals.h"

class Player
{
private:
	void loadPlayerDetail();
	void setupPlayer();

	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;

	sf::Vector2f m_playerSpawn{ SCREEN_WIDTH / 2, 235.0f };

	bool m_alive = true;

public:

	Player();

	sf::Sprite getPlayerBody();
};