//
// Created by AMT on 24/03/2021.
//

#include "Map.h"
#include "Pacman.h"

Map::~Map(){}

Map::Map(float width) {
    if(!font.loadFromFile(FONT_PATH)){
        std::cout << "Font error Map" << std::endl;
    }
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::White);
    text[0].setString("Time");
    text[0].setPosition(sf::Vector2f(width /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 1, 0));

    text[2].setFont(font);
    text[2].setFillColor(sf::Color::White);
    text[2].setString("Score");
    text[2].setPosition(sf::Vector2f(width /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 3, 0));

    text[4].setFont(font);
    text[4].setFillColor(sf::Color::White);
    text[4].setString("FPS");
    text[4].setPosition(sf::Vector2f(width /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 5, 0));
}

int Map::MapRenderer(sf::RenderWindow &w, Map map) {
int level[31][28] = {
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0},
                {0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
                {0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
                {0,3,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,3,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
                {0,2,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,2,0},
                {0,2,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,2,0},
                {0,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,2,2,0},
                {0,0,0,0,0,0,2,0,0,0,0,0,1,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0},
                {1,1,1,1,1,0,2,0,0,0,0,0,1,0,0,1,0,0,0,0,0,2,0,1,1,1,1,1},
                {1,1,1,1,1,0,2,0,0,1,1,1,1,1,1,1,1,1,1,0,0,2,0,1,1,1,1,1},
                {1,1,1,1,1,0,2,0,0,1,0,0,0,7,7,0,0,0,1,0,0,2,0,1,1,1,1,1},
                {0,0,0,0,0,0,2,0,0,1,0,1,1,1,1,1,1,0,1,0,0,2,0,0,0,0,0,0},
                {6,1,1,1,1,1,2,1,1,1,0,1,1,1,1,1,1,0,1,1,1,2,1,1,1,1,1,6},
                {0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0},
                {1,1,1,1,1,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,1,1,1,1,1},
                {1,1,1,1,1,0,2,0,0,1,1,1,1,1,1,1,1,1,1,0,0,2,0,1,1,1,1,1},
                {1,1,1,1,1,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,1,1,1,1,1},
                {0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0},
                {0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
                {0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
                {0,3,2,2,0,0,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,0,0,2,2,3,0},
                {0,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0},
                {0,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0},
                {0,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,2,2,0},
                {0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0},
                {0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        };
    if (!texture.loadFromFile(MAP_BG_PATH))
        std::cout << "Map background error." << std::endl;
    else {
        texture.loadFromFile(MAP_BG_PATH);
        sprite.setTexture(texture);
        sprite.setOrigin(0, -50);
    }
    if (!tileGums.load(MAP_TILESET_GUMS_PATH, sf::Vector2u(16, 16), level, 28, 31))
        std::cout << "Gums Tilemap error" << std::endl;
//    w = 31;
//    h = 28;
//    m[w][h];
//    static TimeManager& instance = TimeManager::GetInstance();
//    static FPS& fps = FPS::GetInstanceFPS();
//    Balls balls;
//    Pinky pinky;
//    Blinky blinky;
//    Inky inky;
//    Clyde clyde;
    Pacman pacman;
//    instance.Start();
//    int i;
    while (w.isOpen()) {
//        sf::Event e;

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                w.close();
            else if (e.type == sf::Event::KeyPressed) {
                std::cout << "kc: " << e.key.code << std::endl;
                switch (e.key.code) {
                    case sf::Keyboard::Up:
                    case sf::Keyboard::Key::W:
//                        case sf::Keyboard::W:
                        std::cout << "Pressed up." << std::endl;
//                        if(level[pacman.GetY()][pacman.GetX()-1] != 0)
                        pacman.SetX(pacman.GetY()-1);
                        if (!tilePacman.move(MAP_TILESET_PACMAN_PATH, sf::Vector2u(16, 16), pacman.GetX() + 1, pacman.GetY()))
                            return -1;
                        break;
                    case sf::Keyboard::Down:
                        std::cout << "Pressed down." << std::endl;
                        break;
                }
            }
        }
        if (!tilePacman.move(MAP_TILESET_PACMAN_PATH, sf::Vector2u(16, 16), pacman.GetX(), pacman.GetY()))
            return -1;
        w.clear();
        w.draw(sprite);
        w.draw(tilePacman);
        w.display();
        sleep(0.1);
    }

    return 0;
}