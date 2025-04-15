#pragma once

#include "Globals.h"
#include "Citadel.h"
#include "Player.h"
#include "Rat.h"

class Game
{
private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processKeyRelease(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void renderCitadel();
	void renderPlayer();
	void renderEnemy();

	// View Window
	sf::RenderWindow m_window;
	sf::RenderTexture m_renderTarget;
	sf::Sprite m_renderTargetSprite;
	sf::View scaledView;

	bool m_exitGame;

	int m_gameMode = PLAY;
	int m_level = CITADEL;
	int m_timeOfDay = SUNRISE;

	// Level Objects
	Citadel m_citadel;

	// Player Objects
	Player m_playerOne;

	// Enemy Objects
	Rat m_rat;

public:

	Game();
	void run();
};

