#pragma once

#include <SFML/Graphics.hpp> 

#include "State.h"

class Game
{
public:
	Game();
	void run();
	void pushState(std::unique_ptr<State> newState);
	void popState();
private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
private:
	sf::RenderWindow mWindow;
	sf::Image mIcon;
	std::vector<std::unique_ptr<State>> mGameStack;
};
