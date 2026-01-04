#pragma once

/******************  Game State Stack *********************************************/

#include <SFML/Graphics.hpp> 
#include <iostream>

#include "World.h"

class Game;

class State
{
protected:
    Game& mGame;
public:
    State(Game& game) : mGame(game) {}
    virtual ~State() = default;
    virtual void handleInput(const sf::Event& event) = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

/******************  AnalogState *********************************************/

class AnalogState : public State
{
private:
    // Game World here
    std::unique_ptr<World> mWorld;
public:
    AnalogState(Game& game);
    void handleInput(const sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

/******************  DigitalState *********************************************/

class DigitalState : public State
{
private:
    sf::Text mCurrentTime;
public:
    DigitalState(Game& game);
    void handleInput(const sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

/******************  InfoState *********************************************/

class InfoState : public State
{
private:
    sf::Font mFont;
    sf::Text mInfoTitle;
    std::vector<sf::Text> mInfoMessages;
    std::vector<std::string> mMessages = {
        "Simple Analog and Digital Watch.",
        "",
        "I was inspired the algorithm suggested by Nick Koumaris:",
        "https://www.youtube.com/watch?v=E_hg96tixLM&t=6s",
        "but my code is differnt.",
		"",
        "Space - Analog / Digital Clock Mode",
        "F1 or I - short information about this game",
        "Esc - quit",
        "",
        "Programmed in C++ with SFML 3 library.",
        "© Oleh Suchalkin  2025-2026"
    };
public:
    InfoState(Game& game);
    void handleInput(const sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
};