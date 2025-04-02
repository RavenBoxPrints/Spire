#include "Game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ 480U, 270U, 32U }, "SFML Game" },
	m_exitGame{false}
{
	/// Creating a viewport that scales images to the window size
	sf::View scaledView(sf::Vector2f{ 240,135 }, sf::Vector2f{ 480,270 }); // First vector is where the center of camera is, second value is full resolution size
	m_window.setView(scaledView);// sets a view on existing window
	m_renderTarget.create(480, 270); // New resolution regardless of window size
	m_renderTargetSprite.setTexture(m_renderTarget.getTexture());
	///
}

void Game::run()
{	
	srand(time(nullptr));

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
#ifdef _DEBUG
			render();
#endif // _DEBUG

		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type)
		{
			m_exitGame = true;
		}

		if (sf::Event::KeyPressed == newEvent.type)
		{
			processKeys(newEvent);
		}
	}
}

void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (t_deltaTime.asMilliseconds() != 16)
	{
		std::cout << "time warp" << std::endl;
	}

	if (m_exitGame)
	{
		m_window.close();
	}
}

void Game::render()
{
	m_window.clear(sf::Color::White);
	
	m_window.display();
}