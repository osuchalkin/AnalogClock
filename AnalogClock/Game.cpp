#include "Constants.h"
#include "Game.h"
#include "ResourceManager.h" 


Game::Game() :
	mWindow(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), GAME_NAME, sf::Style::Close),
	mIcon(),
	mGameStack()
{
	// set window icon AND check assets directory
	if (!mIcon.loadFromFile(ICON_IMAGE))
		throw std::runtime_error("Failed to load png-file from data.");
	mWindow.setIcon(mIcon);

	// loading resources
	ResourceManager::get().loadFont("main", TTF);

	// set mouse position in window's center
	sf::Vector2i windowCenter(mWindow.getSize() / 2u);
	sf::Mouse::setPosition(windowCenter, mWindow);

	// set AnalogState
	mGameStack.push_back(std::move(std::make_unique<AnalogState>(*this)));
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			timeSinceLastUpdate -= TIME_PER_FRAME;

			processEvents();
			update(TIME_PER_FRAME);
		}
		render();
	}
}

void Game::processEvents()
{
	while (const std::optional event = mWindow.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			mWindow.close();
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				mWindow.close();	
		}

		if (mGameStack.empty()) continue;
		mGameStack.back()->handleInput(*event);
	}
}

void Game::update(sf::Time deltaTime)
{
	if (!mGameStack.empty())
		mGameStack.back()->update(deltaTime);
}

void Game::render()
{
	mWindow.clear(BCG_COLOR);

	if (!mGameStack.empty())
	{
		// drawing current state
		mGameStack.back()->render(mWindow);

		// drawing all stack
		//for (const auto& state : mGameStack)
		//{
		//	state->render(mWindow);
		//}
	}

	mWindow.display();
}

void Game::pushState(std::unique_ptr<State> newState)
{
	mGameStack.push_back(std::move(newState));
}

void Game::popState()
{
	if (!mGameStack.empty())
	{
		mGameStack.pop_back();
	}
}
