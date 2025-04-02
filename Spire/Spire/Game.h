#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window;
	sf::RenderTexture m_renderTarget;
	sf::Sprite m_renderTargetSprite;
	sf::View scaledView;

	bool m_exitGame;
};

