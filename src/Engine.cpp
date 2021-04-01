//
// Created by AMT on 15/03/2021.
//

#include <SFML/Window/Event.hpp>
#include "Engine.h"

sf::RenderWindow Engine::window;
Console Engine::console("GameEngine");

void Engine::init() {
    console.print("Initializing engine...");
    // Load ressources
    window.create(sf::VideoMode(640, 480), "LittleBigGame - PacMan");
    console.print("Window has been created.");
    // Game state?
}

bool Engine::isRunning() {
    return window.isOpen();
}

void Engine::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                console.print("Closed. Bye bye.");
                window.close();
                break;
            case sf::Event::KeyPressed:
                // handle keypress
                break;
            case sf::Event::KeyReleased:
                // handle release
                break;
        }
    }
    // game loop?
}

void Engine::render() {
    window.clear();
    // render?
    window.display();
}