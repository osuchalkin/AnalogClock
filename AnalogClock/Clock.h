#pragma once

#include <SFML/Graphics.hpp>
class Clock
{
public:
	Clock(int size, sf::Vector2f position);
	void update();
	void render(sf::RenderWindow& window);
private:
	void drawFace(sf::RenderWindow& window);
	void drawHourMarks(sf::RenderWindow& window);
	void drawHands(sf::RenderWindow& window);
private:
	int mSize;
	sf::Vector2f mCenter;

	sf::CircleShape mClockRim;
	sf::CircleShape mClockFace;
	sf::CircleShape mMark;
	sf::CircleShape mCenterDot;

	sf::RectangleShape mHourMark;
	sf::RectangleShape mHourHand;
	sf::RectangleShape mMinuteHand;
	sf::RectangleShape mSecondHand;
};

