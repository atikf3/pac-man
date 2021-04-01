//
// Created by AMT on 15/03/2021.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "Console.h"

class Engine {
private:
    static sf::RenderWindow window;
    static Console console;

public:
    static void init();
    static bool isRunning();
    static void handleEvents();
    static void render();
};