#include <chrono>
#pragma once
using namespace std::chrono;

class TimeManager {
private:
    time_point<system_clock> start;
    time_point<system_clock> up;
    time_point<system_clock> up2;
public:
    static TimeManager& GetInstance();
    void Start();
    void Update();
    unsigned int GetElapsedTime() const;
    unsigned int GetStartedTime() const;
    TimeManager(const TimeManager &_) = delete;
    TimeManager &operator=(const TimeManager &_) = delete;
//    TimeManager &operator=(TimeManager &&_) = delete;
    TimeManager();
    ~TimeManager();
    static TimeManager tm;
};
