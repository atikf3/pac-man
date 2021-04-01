//
// Created by AMT on 30/03/2021.
//

#pragma once


#include <SFML/System/Clock.hpp>

class FPS {
public:
    FPS() : mFrame(0), mFps(0) {}
    const unsigned int getFPS() const { return mFps; }
    void update();

private:
    unsigned int mFrame;
    unsigned int mFps;
    sf::Clock mClock;
};
