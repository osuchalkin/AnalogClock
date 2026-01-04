#include "World.h"

#include <SFML/Graphics.hpp>
#include <iostream>     // for debugging

#include "Constants.h"


World::World() :
	mClock(std::make_unique<Clock>(DIAMETRE_CLOCK, sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f)))
{
}

void World::checkEvents(const sf::Event& event)
{
}

void World::update(sf::Time deltaTime)
{
    mClock->update();
}

void World::render(sf::RenderWindow& window)
{	
	mClock->render(window);
}

