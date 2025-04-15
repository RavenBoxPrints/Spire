#pragma once

#include "Globals.h"

class Rat
{

private:

	void loadTexture();
	void setup();

	sf::Texture m_ratTexture;
	sf::Sprite m_ratSprite;

	sf::CircleShape m_detect;

	bool m_alive = true;
	int m_heading;
	int m_action = WALK;
	int m_layer = FRONT;

	static const int SPACE = 20; // Distance between sprites

	int m_health = 4;
	float m_speed = 0.1f;

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
	sf::CircleShape getDetect();
	bool getAlive();
	int getLayer();

};