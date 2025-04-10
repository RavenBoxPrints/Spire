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

	int m_playerHeading = NONE;
	int m_playerSpeed = 3;

	int column = 0;
	int row = 0;
	int m_totalFrames = 5;
	float m_frameCounter = 0.0f;
	float m_frameIncrement = 0.3f;

public:

	Player();

	void animatePlayer();
	void setHeading(int t_heading);
	void movePlayerUp();
	void movePlayerDown();
	void movePlayerLeft();
	void movePlayerRight();

	sf::Sprite getPlayerBody();
	bool isAlive();
};