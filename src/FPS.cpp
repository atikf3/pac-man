//
// Created by AMT on 30/03/2021.
//

#include "FPS.h"

void FPS::update() {
    if(mClock.getElapsedTime().asSeconds() >= 1.f) {
        mFps = mFrame;
        mFrame = 0;
        mClock.restart();
    }
    ++mFrame;
}