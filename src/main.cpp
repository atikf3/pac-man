#include <SFML/Graphics.hpp>
#include "Map.h"
#include "ResourceManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(512, 562), "Pac-Man");
    ResourceManager manager;
    if (manager.loadTextures())
        return -1;
    return Menu::initMenu(window);
}