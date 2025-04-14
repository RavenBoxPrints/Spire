#pragma once

#include "Globals.h"

class Rat
{

private:

	void loadTexture();
	void setup();

	sf::Texture m_ratTexture;
	sf::Sprite m_ratSprite;

	bool m_alive = true;
	int m_heading;
	int m_action = WALK;

	int m_health = 4;
	float m_speed = 0.5f;

	int column = 0;
	int row = 0;
	int m_totalFrames = 5;
	float m_frameCounter = 0.0f;
	float m_frameIncrement = 0.15f;


public:

	Rat();

	void spawn();
	void animate();
	void move(sf::Vector2f t_playerPos);

	sf::Sprite getBody();
	bool getAlive();

};