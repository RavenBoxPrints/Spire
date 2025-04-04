#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{ 960U, 480U, 32U }, "SFML Game" },
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

		if (sf::Event::KeyReleased == newEvent.type)
		{
			processKeyRelease(newEvent);
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

void Game::processKeyRelease(sf::Event t_event)
{
	if (sf::Keyboard::Num1 == t_event.key.code)
	{
		m_timeOfDay = SUNRISE;
	}
	if (sf::Keyboard::Num2 == t_event.key.code)
	{
		m_timeOfDay = SUNSET;
	}
	if (sf::Keyboard::Num3 == t_event.key.code)
	{
		m_timeOfDay = NIGHT;
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

	if (m_gameMode == PLAY)
	{
		m_Citadel.animateCitadel(m_timeOfDay);
	}
}

void Game::render()
{
	m_renderTarget.clear(sf::Color::White);
	
	renderCitadel();

	m_renderTarget.display();
	m_window.draw(m_renderTargetSprite);
	m_window.display();
}

void Game::renderCitadel()
{
	if (m_gameMode == PLAY && m_timeOfDay == SUNRISE)
	{
		m_renderTarget.draw(m_Citadel.getSunrise());
		m_renderTarget.draw(m_Citadel.getCloud1());
		m_renderTarget.draw(m_Citadel.getCloud2());
		m_renderTarget.draw(m_Citadel.getCloud3());
		m_renderTarget.draw(m_Citadel.getCloud3Add());
		m_renderTarget.draw(m_Citadel.getCitadel());
		m_renderTarget.draw(m_Citadel.getRay1());
		m_renderTarget.draw(m_Citadel.getRay2());
	}
	if (m_gameMode == PLAY && m_timeOfDay == SUNSET)
	{
		m_renderTarget.draw(m_Citadel.getSunset());
		m_renderTarget.draw(m_Citadel.getCandle());
		m_renderTarget.draw(m_Citadel.getCloud1());
		m_renderTarget.draw(m_Citadel.getCloud2());
		m_renderTarget.draw(m_Citadel.getCloud3());
		m_renderTarget.draw(m_Citadel.getCloud3Add());
		m_renderTarget.draw(m_Citadel.getCitadel());
		m_renderTarget.draw(m_Citadel.getRay1());
		m_renderTarget.draw(m_Citadel.getRay2());
	}
}
