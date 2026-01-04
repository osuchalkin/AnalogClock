#include "State.h"
#include "Game.h"
#include "ResourceManager.h"
#include "TimeUtils.h"


/******************  AnalogState *********************************************/

AnalogState::AnalogState(Game& game) :
    State(game),
    mWorld(std::make_unique<World>())
{
}

void AnalogState::handleInput(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scan::Space)
        {
            mGame.pushState(std::make_unique<DigitalState>(mGame));
        }
        else if (keyPressed->scancode == sf::Keyboard::Scan::F1 ||
            keyPressed->scancode == sf::Keyboard::Scan::I)
        {
            mGame.pushState(std::make_unique<InfoState>(mGame));
        }
    }
};

void AnalogState::update(sf::Time deltaTime)
{
    mWorld->update(deltaTime);
};

void AnalogState::render(sf::RenderWindow& window)
{
    mWorld->render(window);
};

/******************  DigitalState *********************************************/

DigitalState::DigitalState(Game& game) :
    State(game),
    mCurrentTime(ResourceManager::get().getFont("main"), "", 50)
{
	mCurrentTime.setCharacterSize(100);
	mCurrentTime.setFillColor(TEXT_COLOR);
}

void DigitalState::handleInput(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        mGame.popState();
    }
};

void DigitalState::update(sf::Time deltaTime)
{
	float hours = TimeUtils::getCurrentTime().h;
	float minutes = TimeUtils::getCurrentTime().m;
	float seconds = TimeUtils::getCurrentTime().s;

    char buffer[9];
    std::snprintf(buffer, sizeof(buffer), "%02.0f:%02.0f:%02.0f", hours, minutes, seconds);
    mCurrentTime.setString(buffer);
    // center the text
    sf::FloatRect textRect = mCurrentTime.getLocalBounds();
    mCurrentTime.setOrigin(textRect.size / 2.0f);
    mCurrentTime.setPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3 });
};

void DigitalState::render(sf::RenderWindow& window)
{
	window.draw(mCurrentTime);
};

/******************  InfoState *********************************************/

InfoState::InfoState(Game& game) :
    State(game),
    mFont(ResourceManager::get().getFont("main")),
    mInfoTitle(mFont, "Clock", 50),
    mInfoMessages()
{
    // set InfoTitle
    mInfoTitle.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = mInfoTitle.getLocalBounds();
    mInfoTitle.setOrigin(textRect.size / 2.0f);
    mInfoTitle.setPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 7 });
    mInfoTitle.setFillColor(TEXT_COLOR);

    // set InfoText
    for (size_t i = 0; i < mMessages.size(); ++i)
    {
        sf::Text text(mFont, mMessages[i], 20);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.size / 2.0f);
        text.setPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3.5f + static_cast<float>(i) * 30 });
        text.setFillColor(TEXT_COLOR);

        mInfoMessages.push_back(text);
    }
}

void InfoState::handleInput(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        mGame.popState();
    }
}

void InfoState::update(sf::Time deltaTime)
{
}

void InfoState::render(sf::RenderWindow& window)
{
    window.draw(mInfoTitle);
    for (const auto& text : mInfoMessages)
        window.draw(text);
}
