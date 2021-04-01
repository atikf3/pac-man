#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "ResourceManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(512, 562), "Pac-Man");
    window.setFramerateLimit(60);
//    widow.setVerticalSyncEnabled(true);
    ResourceManager manager;
    if (manager.loadTextures())
        return -1;
    return Menu::initMenu(window);
}