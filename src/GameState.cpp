//
// Created by AMT on 31/03/2021.
//

#include "GameState.h"

GameState::GameState() {
    status = Type::None;
}

GameState::~GameState() {}

void GameState::init() {
    console = new Console("GameState");
    // create pacman etc here
    console->print("init done.");
}

GameState::Type GameState::GetState() {
    return status;
}

void GameState::SetState(GameState::Type state) {
    GameState::status = state;
}

void GameState::keyPressed(int kCode) {}

void GameState::keyReleased(int kCode) {}

