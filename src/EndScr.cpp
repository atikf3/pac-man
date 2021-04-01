//
// Created by AMT on 09/03/2021.
//
#include "EndScr.h"
Console EndScreen::console("EndScreen");

int EndScreen::initEnd(sf::RenderWindow& window, int pacmanLife) {
    EndScreen end(window.getSize().x, window.getSize().y, pacmanLife);
//    Map map(window.getSize().x);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            end.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            end.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (end.GetPressedItem()) {
                                case 1:
                                    console.print("Back to menu");
                                    return 1;
                                    break;
                                case 2:
                                    console.print("Closing game!");
                                    return 0;
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
        end.draw(window);
        window.display();
    }
    return 0;
}

EndScreen::EndScreen(float width, float height, int pacmanLife) {
    console.print("Loading endmenu ...");
    if (!font.loadFromFile(FONT_PATH)) {
        std::cout << "Font not found!" << std::endl;
    }

    menu[0].setFont(font);
    menu[0].setColor(pacmanLife > 0 ? sf::Color::Green : sf::Color::Red);
    menu[0].setString(pacmanLife > 0 ? "You won!" : "You lost!");
    menu[0].setPosition(sf::Vector2f(width / 2.5, height / (MAX_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Menu");
    menu[1].setPosition(sf::Vector2f(width / 2.5, height / (MAX_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2.5, height / (MAX_ITEMS + 1) * 3));

    selectedItemIndex = 1;
}


EndScreen::~EndScreen() {}

void EndScreen::draw(sf::RenderWindow& window) {
    for (int i = 0; i < MAX_ITEMS; i++)
        window.draw(menu[i]);
}

void EndScreen::MoveUp() {
    if (selectedItemIndex - 1 > 0) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Yellow);
    }
}

void EndScreen::MoveDown() {
    if (selectedItemIndex + 1 < MAX_ITEMS) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Yellow);
    }
}