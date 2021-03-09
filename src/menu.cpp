//
// Created by AMT on 09/03/2021.
//
#include "menu.h"

 int Menu::initMenu(sf::RenderWindow& window) {
    Menu menu(window.getSize().x, window.getSize().y);
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    break;
                                case 1:
                                    std::cout << "Option button has been pressed" << std::endl;
                                    break;
                                case 2:
                                    window.close();
                                    break;
                            }

                            break;
                    }

                    break;
                case sf::Event::Closed:
                    window.close();

                    break;

            }
        }

        window.clear();

        menu.draw(window);

        window.display();
    }
    return 0;
}

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("../src/assets/fonts/Roboto-Regular.ttf")) {
        std::cout << "Font not found!" << std::endl;
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}


Menu::~Menu() {}

void Menu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < MAX_ITEMS; i++)
        window.draw(menu[i]);
}

void Menu::MoveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown() {
    if (selectedItemIndex + 1 < MAX_ITEMS) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}