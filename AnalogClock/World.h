#pragma once

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Clock.h"

class World
{
public:
	World();
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window);
	void checkEvents(const sf::Event& event);
private:
	std::unique_ptr<Clock> mClock;
};

