//
// Created by AMT on 31/03/2021.
//

#pragma once


#include "Console.h"
#include "Map.h"


class GameState {
public:
    GameState();
    ~GameState();
    enum Type {
        Failure = -1,
        None = 0,
        Init = 1,
        Playing = 2,
        End = 3,
    };
    void keyPressed(int kCode);
    void keyReleased(int kCode);
    Type GetState();
    void SetState(Type _state);
    static void init();
private:
    static Console console;
    Type status;
};
