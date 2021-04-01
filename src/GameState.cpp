//
// Created by AMT on 31/03/2021.
//

#include "GameState.h"
Console GameState::console("GameState");

GameState::GameState() {
    status = Type::None;
}

GameState::~GameState() {}

void GameState::init() {
    // create pacman etc here
    console.print("init done.");
}

GameState::Type GameState::GetState() {
    return status;
}

void GameState::SetState(GameState::Type state) {
    GameState::status = state;
    console.print("State has changed.");
}

void GameState::keyPressed(int kCode) {}

void GameState::keyReleased(int kCode) {}

