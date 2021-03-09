#include <SFML/Graphics.hpp>
#include "menu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "bubbleMind");
    Menu::initMenu(window);
    return 0;
}