#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Globals.h"
#include "Citadel.h"

class Game
{
private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void renderCitadel();

	// View Window
	sf::RenderWindow m_window;
	sf::RenderTexture m_renderTarget;
	sf::Sprite m_renderTargetSprite;
	sf::View scaledView;

	bool m_exitGame;

	Citadel m_Citadel;

	int m_level = CITADEL;
	int m_gameMode = PLAY;
	int m_timeOfDay = SUNRISE;

public:

	Game();
	void run();
};

