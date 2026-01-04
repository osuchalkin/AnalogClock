#include "Clock.h"
#include "Constants.h"
#include "TimeUtils.h"


Clock::Clock(int size, sf::Vector2f position) :
	mSize(size),
	mCenter(position),
	mClockRim(size / 2.f),
	mClockFace(size / 2.f - 40),
	mMark(size / 2.f - 50),
	mCenterDot(15.f),
	mHourMark(sf::Vector2f(10.f, size / 2.f)),
	mHourHand(sf::Vector2f(size * 0.25f, size * 0.03f)),
	mMinuteHand(sf::Vector2f(size * 0.35f, size * 0.02f)),
	mSecondHand(sf::Vector2f(size * 0.40f, size * 0.01f))
{
	// Clock rim
	mClockRim.setPointCount(100);
	mClockRim.setFillColor(RIM_COLOR);
	mClockRim.setOrigin({ mClockRim.getRadius(), mClockRim.getRadius() });
	mClockRim.setPosition(mCenter);
	// Clock face
	mClockFace.setPointCount(100);
	mClockFace.setFillColor(sf::Color::White);
	mClockFace.setOutlineColor(RIM_BORDER_COLOR);
	mClockFace.setOutlineThickness(10.f);
	mClockFace.setOrigin({ mClockFace.getRadius(), mClockFace.getRadius() });
	mClockFace.setPosition(mCenter);
	// Mark (circle for shadow marks)
	mMark.setPointCount(100);
	mMark.setFillColor(sf::Color::White);
	mMark.setOrigin({ mMark.getRadius(), mMark.getRadius() });
	mMark.setPosition(mCenter);

	// Center dot
	mCenterDot.setFillColor(RIM_COLOR);
	mCenterDot.setOrigin({ mCenterDot.getRadius(), mCenterDot.getRadius() });
	mCenterDot.setPosition(mCenter);

	// Hour mark
	mHourMark.setOrigin({ mHourMark.getSize().x / 2.f, mHourMark.getSize().y - 30.f });
	mHourMark.setFillColor(RIM_COLOR);
	mHourMark.setPosition(mCenter);

	// Hour hand
	mHourHand.setFillColor(sf::Color::Black);
	mHourHand.setOrigin({ 0.f, mHourHand.getSize().y / 2.f });
	mHourHand.setPosition(mCenter);
	// Minute hand
	mMinuteHand.setFillColor(sf::Color::Black);
	mMinuteHand.setOrigin({ 0.f, mMinuteHand.getSize().y / 2.f });
	mMinuteHand.setPosition(mCenter);
	// Second hand
	mSecondHand.setFillColor(sf::Color::Red);
	mSecondHand.setOrigin({ 0.f, mSecondHand.getSize().y / 2.f });
	mSecondHand.setPosition(mCenter);
}

void Clock::update()
{
	TimeData timeData = TimeUtils::getCurrentTime();
	float hours = timeData.h;
	float minutes = timeData.m;
	float seconds = timeData.s;

	// Calculate angles
	float hourAngle = hours * 30.f + (minutes / 60) * 30;
	float minuteAngle = minutes * 6.f; 
	float secondAngle = seconds * 6.f; 
	// Update hand rotations
	mHourHand.setRotation(sf::degrees(hourAngle - 90.f));   // -90 to start from top
	mMinuteHand.setRotation(sf::degrees(minuteAngle - 90.f));
	mSecondHand.setRotation(sf::degrees(secondAngle - 90.f));
}

void Clock::render(sf::RenderWindow& window)
{
	drawFace(window);
	drawHourMarks(window);
	drawHands(window);
}

void Clock::drawFace(sf::RenderWindow& window)
{
	window.draw(mClockRim);
	window.draw(mClockFace);
}

void Clock::drawHourMarks(sf::RenderWindow& window)
{
	for (int i = 0; i < 12; i++)
	{
		mHourMark.setRotation(sf::degrees(i * 30));
		window.draw(mHourMark);
	}
	window.draw(mMark);
}

void Clock::drawHands(sf::RenderWindow& window)
{
	window.draw(mHourHand);
	window.draw(mMinuteHand);
	window.draw(mSecondHand);
	window.draw(mCenterDot);
}