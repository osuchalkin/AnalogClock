#pragma once

#include<SFML/Graphics.hpp>
#include<string>

// Game's name
const std::string GAME_NAME = "Analog Clock";

// FPS
const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 15.f);

// Window dimensions
constexpr unsigned int SCREEN_WIDTH = 600;
constexpr unsigned int SCREEN_HEIGHT = 600;
// Clock diameter
constexpr float DIAMETRE_CLOCK = 500.f;

// Colors
const sf::Color BCG_COLOR(sf::Color(225, 239, 240));
const sf::Color RIM_COLOR(sf::Color(45, 45, 45));
const sf::Color RIM_BORDER_COLOR(sf::Color(229, 229, 229));
const sf::Color TEXT_COLOR(sf::Color::Black);

// resources
const std::string ICON_IMAGE = "assets/textures/clock.png";
const std::string TTF = "assets/fonts/Roboto-Regular.ttf";
