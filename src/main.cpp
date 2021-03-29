#include <SFML/Graphics.hpp>
#include "menu.h"
#include "Map.h"

int main() {
//    sf::RenderWindow window(sf::VideoMode(640, 480), "bubbleMind");
    sf::RenderWindow window(sf::VideoMode(512, 562), "bubbleMind");
//    Menu::initMenu(window);
    // on définit le niveau à l'aide de numéro de tuiles
    Map map(window.getSize().x);
//    while (window.isOpen()) {
//
//    }
    map.MapRenderer(window, map);
    return 0;
//    while (w.isOpen()) {
//        sf::Event e;
//
//        while (w.pollEvent(e)) {
//            if (e.type == sf::Event::Closed)
//                w.close();
//            else if (e.type == sf::Event::KeyReleased) {
//                switch (event.key.code) {
//                    case sf::Keyboard::Up:
//                        std::cout << "Pressed up." << std::endl;
//                        break;
//                    case sf::Keyboard::Down:
//                        std::cout << "Pressed down." << std::endl;
//                        break
//                }
//            }
//        }
//        w.clear();
//        w.draw(sprite);
//        w.display();
//        sleep(0.1);
//    }
}