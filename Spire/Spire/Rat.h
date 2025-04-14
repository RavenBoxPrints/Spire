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
	float m_speed = 1.0f;


public:

	Rat();

	void spawn();
	sf::Sprite getBody();
	bool getAlive();

};